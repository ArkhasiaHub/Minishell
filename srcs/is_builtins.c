/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:14:53 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/07 12:22:03 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtins_one(char *str)
{
	if (ft_strncmp(str, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(str, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(str, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(str, "export", 7) == 0)
		return (1);
	if (ft_strncmp(str, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(str, "env", 4) == 0)
		return (1);
	if (ft_strncmp(str, "exit", 5) == 0)
		return (1);
	return (0);
}

int	is_environment_builtins(t_minishell *m)
{
	if (ft_strncmp(m->c->args[0], "export", 7) == 0)
	{
		m->c->builtins = EXPORT;
		return (1);
	}
	if (ft_strncmp(m->c->args[0], "unset", 6) == 0)
	{
		m->c->builtins = UNSET;
		return (1);
	}
	if (ft_strncmp(m->c->args[0], "env", 4) == 0)
	{
		m->c->builtins = ENV;
		return (1);
	}
	return (0);
}

int	is_builtins(t_minishell *m)
{
	if (ft_strncmp(m->c->args[0], "echo", 5) == 0)
	{
		m->c->builtins = FT_ECHO;
		return (1);
	}
	if (ft_strncmp(m->c->args[0], "cd", 3) == 0)
	{
		m->c->builtins = CD;
		return (1);
	}
	if (ft_strncmp(m->c->args[0], "pwd", 4) == 0)
	{
		m->c->builtins = PWD;
		return (1);
	}
	if (is_environment_builtins(m) == 1)
		return (1);
	if (ft_strncmp(m->c->args[0], "exit", 5) == 0)
	{
		m->c->builtins = EXIT;
		return (1);
	}
	return (0);
}
