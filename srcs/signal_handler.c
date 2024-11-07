/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:05:02 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/11 10:32:44 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_status_signal;

static void	signal_child_handler(int sig);
static void	signal_here_doc_handler(int sig);

int	handling_signal(int m)
{
	struct sigaction	sig;

	if (m == SIG_MAIN)
		set_process_handle();
	else if (m == SIG_CHILD)
	{
		sig.sa_handler = signal_child_handler;
		sigemptyset(&sig.sa_mask);
		sig.sa_flags = SA_SIGINFO;
		sigaction(SIGINT, &sig, NULL);
		sigaction(SIGQUIT, &sig, NULL);
	}
	else if (m == SIG_HEREDOC)
	{
		sig.sa_handler = signal_here_doc_handler;
		sigemptyset(&sig.sa_mask);
		sig.sa_flags = 0;
		sigaction(SIGINT, &sig, NULL);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (m == SIG_PARENT)
		set_process_child();
	return (1);
}

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_status_signal = 130;
		write(2, "\n", 2);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	signal_here_doc_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_status_signal = 130;
		write(2, "\n", 2);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

static void	signal_child_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_status_signal = 130;
		write(2, "\n", 2);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		g_status_signal = 131;
		write(2, "quit (core dumped) ", 20);
	}
}
