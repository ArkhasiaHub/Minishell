/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:03:42 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/08 14:16:04 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	manage_pipe(t_commands *cmds, int *first_pipe);

int	exec_cmds(t_minishell *shell, t_commands *cmds)
{
	int		redir;
	int		fd[MAX_PIPE];
	int		first_pipe;

	first_pipe = -1;
	redir = cmds->infile;
	while (cmds->next != NULL)
	{
		if (pipe(fd) == -1)
			return (-1);
		if (cmds->here_doc == NULL)
			cmds->infile = redir;
		cmds->outfile = fd[WR];
		create_process(shell, cmds, shell->envp, fd[RD]);
		manage_pipe(cmds, &first_pipe);
		close(fd[WR]);
		redir = fd[RD];
		if (first_pipe == -1)
			first_pipe = fd[RD];
		cmds = cmds->next;
	}
	if (cmds->here_doc == NULL)
		cmds->infile = redir;
	create_process(shell, cmds, shell->envp, -1);
	return (closing_fds(cmds), wait_all_pids(shell->c), 0);
}

static void	manage_pipe(t_commands *cmds, int *first_pipe)
{
	if (*first_pipe != -1 && *first_pipe != -2)
	{
		close(*first_pipe);
		if (cmds->next->next == NULL)
			*first_pipe = -2;
		else
			*first_pipe = -1;
	}
}

void	closing_fds(t_commands *c)
{
	if (c->infile != 0 && c->infile != -1)
		close(c->infile);
	if (c->outfile != 1 && c->outfile != -1)
		close(c->outfile);
}
