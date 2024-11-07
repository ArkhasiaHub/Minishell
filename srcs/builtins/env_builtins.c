/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:17:52 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/11 09:35:10 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_builtins(t_minishell *shell, t_commands *c, int outfile, int len)
{
	int	i;

	if (len > 1)
	{
		printf("env: '%s': No such file or directory\n", c->args[1]);
		g_status_signal = 127;
		return ;
	}
	i = 0;
	while (shell->envp[i])
	{
		write(outfile, shell->envp[i], ft_strlen(shell->envp[i]));
		write(outfile, "\n", 1);
		i++;
	}
}
