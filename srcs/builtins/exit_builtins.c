/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:17:23 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/08 14:46:06 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static long long	exit_check_args(char **args, int len);
static int			is_strnum(char *str, int op);

void	exit_builtins(t_minishell *shell, char **args, int len)
{
	long long	exit_status;

	exit_status = g_status_signal;
	if (args == NULL)
		free_minishell(shell, g_status_signal);
	exit_status = exit_check_args(args, len);
	if (exit_status == -2)
	{
		write(2, "Too many arguments\n", 20);
		return ;
	}
	if (exit_status == 2)
		free_minishell(shell, 2);
	free_minishell(shell, (unsigned char)exit_status);
}

static long long	exit_check_args(char **args, int len)
{
	int			j;
	long long	nb;

	j = 0;
	if (!is_strnum(args[0], 1))
	{
		write(2, "Numerical arguments needed\n", 28);
		return (2);
	}
	if (len > 2)
		return (-2);
	if (args[0][j] == '-' || args[0][j] == '+')
		j++;
	while (args[0][j] && args[0][j] == '0')
		j++;
	nb = ft_atol(args[0]);
	return (nb);
}

static int	is_strnum(char *str, int op)
{
	int	i;

	i = 0;
	if (!op)
	{
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
		}
		return (1);
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
