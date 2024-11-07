/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:43:28 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/07 12:38:42 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	list_size(t_commands *cmds)
{
	int	len;

	len = 0;
	while (cmds != NULL)
	{
		cmds = cmds->next;
		len++;
	}
	return (len);
}

void	wait_all_pids(t_commands *cmds)
{
	while (cmds)
	{
		if (cmds->pid != -1)
			waitpid(cmds->pid, NULL, 0);
		cmds = cmds->next;
	}
}
