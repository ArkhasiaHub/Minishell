/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:36:31 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/08 16:55:59 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_len(t_minishell *m, char *str, int *len)
{
	int	quote;

	m->i = 0;
	quote = NONE;
	while (str[m->i])
	{
		change_quote(str, m, &quote);
		if (quote == DOUBLE || quote == NONE)
		{
			if (str[m->i] == '$')
			{
				if (manage_env_variable(m, len, str) == -1)
					return (-2);
			}
		}
		m->i++;
		*len += 1;
	}
	if (quote != NONE)
		return (-1);
	return (0);
}

void	change_quote(char *str, t_minishell *m, int *quote)
{
	if (str[m->i] == '"' && *quote == NONE)
	{
		*quote = DOUBLE;
	}
	else if (str[m->i] == '"' && *quote == DOUBLE)
	{
		*quote = NONE;
	}
	else if (str[m->i] == '\'' && *quote == NONE)
	{
		*quote = SIMPLE;
	}
	else if (str[m->i] == '\'' && *quote == SIMPLE)
	{
		*quote = NONE;
	}
}
