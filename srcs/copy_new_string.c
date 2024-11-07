/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_new_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:51:16 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/08 14:31:00 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_protect(t_minishell *m, char *dst, int *j, int protect);
static void	init_val_cpy(t_minishell *m, int *j, int *quote);
static void	cpy_string(t_minishell *m, char *str, char *dst, int *j);
static int	check_cpy(t_minishell *m, char *str, int quote, int j[4]);

int	copy_new_string(char *str, char *dst, t_minishell *m)
{
	int	quote;
	int	j[4];

	init_val_cpy(m, &(j[0]), &quote);
	while (str[++(m->i)] != '\0')
	{
		j[3] = 0;
		j[1] = quote;
		change_quote(str, m, &quote);
		if (quote == DOUBLE || quote == NONE)
		{
			if (str[m->i] == '$')
			{
				j[2] = copy_env_variable(m, &(j[0]), str, dst);
				if (check_protect(m, dst, &(j[0]), j[2]) == -1)
					return (-1);
				j[3] = 1;
			}
		}
		if (check_cpy(m, str, quote, j) == 1)
			cpy_string(m, str, dst, &j[0]);
	}
	dst[j[0]] = '\0';
	return (0);
}

static void	cpy_string(t_minishell *m, char *str, char *dst, int *j)
{
	dst[*j] = str[m->i];
	(*j) += 1;
}

static void	init_val_cpy(t_minishell *m, int *j, int *quote)
{
	m->i = -1;
	*j = 0;
	*quote = NONE;
}

static int	check_protect(t_minishell *m, char *dst, int *j, int protect)
{
	if (protect == -1)
		return (-1);
	if (protect == 1)
	{
		if (copy_errno(j, dst, m) == -1)
			return (-1);
	}
	return (0);
}

static int	check_cpy(t_minishell *m, char *str, int quote, int j[4])
{
	if ((size_t) m->i < ft_strlen(str) && str[m->i] && \
		j[3] == 0 && str[m->i] != quote && str[m->i] != j[1])
	{
		if (quote == NONE && str[m->i] == '"')
			return (0);
		return (1);
	}
	return (0);
}
