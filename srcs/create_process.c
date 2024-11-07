/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:52:50 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/08 14:58:21 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		is_builtins_process(t_minishell *shell, t_commands *c);
static void	close_standard_fd(t_commands *c);
static void	set_pid_status(t_commands *c, pid_t pid);

int	create_process(t_minishell *shell, t_commands *c, char **envp, int to_close)
{
	pid_t	pid;

	if (!c->path)
		return (1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		handling_signal(SIG_CHILD);
		if (c->infile == -1)
			exit(1);
		if (dup2(c->infile, STDIN_FILENO) == -1)
			exit(1);
		if (dup2(c->outfile, STDOUT_FILENO) == -1)
			exit(1);
		if (to_close != -1)
			close(to_close);
		closing_fds(c);
		is_builtins_process(shell, c);
		execve(c->path, c->args, envp);
		return (perror(c->args[0]), -1);
	}
	g_status_signal = errno;
	return (set_pid_status(c, pid), handling_signal(SIG_PARENT));
}

static void	set_pid_status(t_commands *c, pid_t pid)
{
	c->pid = pid;
}

void	is_builtins_process(t_minishell *shell, t_commands *c)
{
	if (c->is_builtins == true)
	{
		exec_builtins(shell, c);
		close_standard_fd(c);
		exit(0);
	}
}

static void	close_standard_fd(t_commands *c)
{
	if (c->is_builtins && c->next != NULL)
	{
		close(0);
		close(1);
		close(2);
	}
}
