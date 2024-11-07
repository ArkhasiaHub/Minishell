/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:43:54 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/08 09:40:28 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_node(t_minishell *m)
{
	t_commands	*new;

	if (!m->c)
	{
		m->c = ft_calloc(sizeof(t_commands), 1);
		if (!m->c)
			return (-1);
		m->c->outfile = 1;
		m->c->infile = 0;
		m->c->here_doc = NULL;
		m->c->next = NULL;
		return (0);
	}
	new = ft_calloc(sizeof(t_commands), 1);
	while (m->c->next != NULL)
		m->c = m->c->next;
	new->previous = m->c;
	new->outfile = 1;
	new->infile = 0;
	new->next = NULL;
	new->here_doc = NULL;
	m->c->next = new;
	m->c = m->c->next;
	return (0);
}

void	begin_list(t_minishell *m)
{
	while (m->c && m->c->previous != NULL)
		m->c = m->c->previous;
}
