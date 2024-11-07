/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:00:21 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/08 14:46:34 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_one(t_minishell *m, char *str)
{
	if (is_builtins_one(str) == 1)
		return (1);
	else if (is_absolute_one(str) == 1)
		return (1);
	else if (is_cmd_one(m, str) == 1)
		return (1);
	return (0);
}

void	check_last(t_minishell *m)
{
	int	cmd;

	cmd = 0;
	m->c->is_builtins = false;
	if (m->c->args[0] == NULL)
		return ;
	if (is_builtins(m) == 1)
	{
		m->c->is_builtins = true;
		m->c->path = ft_strdup(m->c->args[0]);
		cmd = 1;
	}
	else if (is_absolute(m) == 1)
	{
		m->c->path = ft_strdup(m->c->args[0]);
		cmd = 1;
	}
	else if (is_cmd(m) == 1)
		cmd = 1;
	if (cmd == 0)
	{
		printf("%s: command not found\n", m->c->args[0]);
		m->c->path = NULL;
		g_status_signal = 127;
	}
}

void	all_check(t_minishell *m, int *cmd)
{
	if (is_builtins(m) == 1)
	{
		m->c->path = ft_strdup(m->c->args[0]);
		if (!m->c->path)
			free_minishell(m, EXIT_FAILURE);
		m->c->is_builtins = true;
		*cmd = 1;
	}
	else if (is_absolute(m) == 1)
	{
		m->c->path = ft_strdup(m->c->args[0]);
		if (!m->c->path)
			free_minishell(m, EXIT_FAILURE);
		*cmd = 1;
	}
	else if (is_cmd(m) == 1)
		*cmd = 1;
}

void	check_cmd(t_minishell *m)
{
	int	cmd;

	cmd = 0;
	m->c->is_builtins = false;
	while (m->c->next != NULL)
	{
		all_check(m, &cmd);
		if (cmd == 0)
		{
			printf("%s: command not found\n", m->c->args[0]);
			g_status_signal = 127;
			m->c->path = NULL;
		}
		m->c = m->c->next;
	}
	check_last(m);
}
