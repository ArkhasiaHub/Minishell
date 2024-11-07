/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:23:29 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/06 15:31:26 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_previous(t_minishell *m);
static void	clean_next(t_minishell *m);
static void	set_cmds_default(t_minishell *m, int next);

void	clean_list(t_minishell *m)
{
	while (m->c->next != NULL)
		m->c = m->c->next;
	if (m->c->previous != NULL)
		m->c = m->c->previous;
	clean_previous(m);
	clean_next(m);
	if (m->c->args)
	{
		free_split(m->c->args);
		m->c->args = NULL;
	}
	if (m->c->here_doc)
	{
		free(m->c->here_doc);
		m->c->here_doc = NULL;
	}
	if (m->c->path)
	{
		free(m->c->path);
		m->c->path = NULL;
	}
	set_cmds_default(m, 0);
	free(m->c);
	m->c = NULL;
}

static void	clean_previous(t_minishell *m)
{
	while (m->c->previous != NULL)
	{
		if (m->c->next)
		{
			if (m->c->next->args)
			{
				free_split(m->c->next->args);
				m->c->next->args = NULL;
			}
			if (m->c->next->here_doc)
			{
				free(m->c->next->here_doc);
				m->c->next->here_doc = NULL;
			}
			if (m->c->next->path)
			{
				free(m->c->next->path);
				m->c->next->path = NULL;
			}
			set_cmds_default(m, 1);
			free(m->c->next);
			m->c->next = NULL;
		}
		m->c = m->c->previous;
	}
}

static void	clean_next(t_minishell *m)
{
	if (m->c->next)
	{
		if (m->c->next->args)
		{
			free_split(m->c->next->args);
			m->c->next->args = NULL;
		}
		if (m->c->next->here_doc)
		{
			free(m->c->next->here_doc);
			m->c->next->here_doc = NULL;
		}
		if (m->c->next->path)
		{
			free(m->c->next->path);
			m->c->next->path = NULL;
		}
		set_cmds_default(m, 1);
		free(m->c->next);
		m->c->next = NULL;
	}
}

static void	set_cmds_default(t_minishell *m, int next)
{
	if (next)
	{
		m->c->next->builtins = false;
		m->c->next->infile = 0;
		m->c->next->outfile = 1;
		return ;
	}
	m->c->builtins = false;
	m->c->infile = 0;
	m->c->outfile = 1;
}
