/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:03:22 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/11 10:52:52 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_status_signal;

void	here_doc(t_minishell *m)
{
	char	*test;

	handling_signal(SIG_HEREDOC);
	while (1)
	{
		test = get_next_line(0);
		if (!test && g_status_signal != 130)
		{
			printf(" warning: here-document at line 1 \
				delimited by end-of-file (wanted '%s')\n", m->c->here_doc);
			break ;
		}
		if (g_status_signal == 130)
			break ;
		test[ft_strlen(test) - 1] = '\0';
		if (strncmp(test, m->c->here_doc, ft_strlen(m->c->here_doc)) == 0 && \
			ft_strlen(m->c->here_doc) == ft_strlen(test))
			break ;
		ft_putstr_fd(test, m->c->infile);
		ft_putstr_fd("\n", m->c->infile);
		free(test);
	}
	free(test);
}
