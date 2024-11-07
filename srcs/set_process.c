/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:26:13 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/08 14:32:14 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	signal_parent_handler(int sig);

void	set_process_handle(void)
{
	struct sigaction	sig;

	sig.sa_handler = signal_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	sigaction(SIGINT, &sig, NULL);
	signal(SIGQUIT, SIG_IGN);
}

void	set_process_child(void)
{
	struct sigaction	sig;

	sig.sa_handler = signal_parent_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &sig, NULL);
}

static void	signal_parent_handler(int sig)
{
	g_status_signal = sig;
	if (sig == SIGINT)
		write(2, "\n", 2);
	else if (sig == SIGQUIT)
		write(2, "quit (core dumped)\n", 20);
}
