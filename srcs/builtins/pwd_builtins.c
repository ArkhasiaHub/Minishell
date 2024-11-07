/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:17:01 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/04 15:09:48 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd(t_minishell *shell, int argc, int ouftile)
{
	if (argc > 1)
		write(2, "pwd: to many arguments\n", 24);
	else
	{
		write(ouftile, shell->pwd, ft_strlen(shell->pwd));
		write(ouftile, "\n", 2);
	}
}
