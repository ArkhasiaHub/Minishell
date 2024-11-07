/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:11:12 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/08 17:11:40 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	last_check(char *arg, char *final, int *i, int *k);
int			manage_unclose(void);

void	last_line_unclosed(char *line, char *temp, char *temp2, int quote)
{
	char	*temp3;
	int		i;

	i = 0;
	while ((quote == DOUBLE && line[i] != '"') || \
		(quote == SIMPLE && line[i] != '\''))
		i++;
	if (i != 0)
	{
		temp2 = ft_substr(line, 0, i);
		line = line + i + 1;
		temp3 = ft_strjoin(temp2, line);
		free(line);
		free(temp2);
		temp = ft_strjoin(temp, temp3);
		free(temp3);
	}
	else
		free(line);
}

int	count_quote(char *line, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	manage_quote(t_minishell *m, char *str, int *i, int *k)
{
	int		size;
	int		temp;
	char	*temp2;

	size = 0;
	if (ft_strchr(str, '"') != 0 || ft_strchr(str, '\'') != 0)
	{
		temp = quote_len(m, str, &size);
		if (temp == -2)
			free_minishell(m, EXIT_FAILURE);
		if (temp == -1)
			return (manage_unclose());
		temp2 = ft_calloc(sizeof(char), size);
		if (!temp2)
			return (-1);
		if (copy_new_string(str, temp2, m) == -1)
			return (free(temp2), -1);
		m->c->args[*k] = ft_strdup(temp2);
		last_check(m->c->args[*k], temp2, i, k);
		return (1);
	}
	return (0);
}

static int	last_check(char *arg, char *final, int *i, int *k)
{
	if (!arg)
		return (free(final), -1);
	*i = *i + 1;
	*k = *k + 1;
	return (free(final), 1);
}

int	manage_unclose(void)
{
	printf("Invalid arg : unclosed quote\n");
	return (-1);
}
