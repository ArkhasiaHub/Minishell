/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_with_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:39:42 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/07 10:31:42 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_out(t_minishell *m, char *temp, int size, int *j)
{
	if ((m->i + 1 == size && m->line[m->i] == '>') \
		|| (m->line[m->i] == '>' && m->line[m->i + 1] != '>'))
	{
		*j = manage_space_out(m, m->i, *j, temp);
		m->i++;
	}
	else if (m->i + 1 < size && (m->line[m->i] == '>' \
		&& m->line[m->i + 1] == '>'))
	{
		*j = manage_space_app(m, m->i, *j, temp);
		m->i = m->i + 2;
	}
}

void	copy_in(t_minishell *m, char *temp, int size, int *j)
{
	if ((m->i + 1 == size && m->line[m->i] == '<') \
		|| (m->line[m->i] == '<' && m->line[m->i + 1] != '<'))
	{
		*j = manage_space_in(m, m->i, *j, temp);
		m->i++;
	}
	else if (m->i + 1 < size && (m->line[m->i] == '<' \
		&& m->line[m->i + 1] == '<'))
	{
		*j = manage_space_here_doc(m, m->i, *j, temp);
		m->i += 2;
	}
}

void	copy_txt_pipe(t_minishell *m, char *temp, int *j)
{
	if (m->line[m->i] == '|')
	{
		*j = manage_space_pipe(m, m->i, *j, temp);
		m->i++;
	}
	else
	{
		temp[*j] = m->line[m->i];
		*j = *j + 1;
		m->i++;
	}
}

void	copy_with_space(t_minishell *m)
{
	char	*temp;
	int		size;
	int		j;
	int		check;

	m->i = 0;
	j = 0;
	size = size_with_space(m->line);
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		free_minishell(m, EXIT_FAILURE);
	while (m->line[m->i])
	{
		check = m->i;
		copy_out(m, temp, size, &j);
		if (check == m->i)
			copy_in(m, temp, size, &j);
		check = m->i;
		if (check == m->i)
			copy_txt_pipe(m, temp, &j);
	}
	temp[j] = '\0';
	free(m->line);
	m->line = temp;
}
