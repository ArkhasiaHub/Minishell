/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:22:28 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/08 14:17:22 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_minishell(t_minishell *shell)
{
	if (shell->line)
	{
		free(shell->line);
		shell->line = NULL;
	}
	if (shell->c)
		clean_list(shell);
	if (shell->tmp_heredoc && access(shell->tmp_heredoc, F_OK) == 0)
		unlink(shell->tmp_heredoc);
}
