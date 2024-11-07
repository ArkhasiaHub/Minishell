/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:26:28 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/07 12:36:54 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fill_path(t_minishell *m, char *cmd)
{
	m->c->path = ft_strdup(cmd);
	if (!m->c->path)
	{
		free(cmd);
		free_minishell(m, EXIT_FAILURE);
	}
	free(cmd);
	return (1);
}

int	is_cmd_one(t_minishell *m, char *str)
{
	int		i;
	char	*cmd;
	char	*temp;

	i = -1;
	if (m->path == NULL || ft_strchr(str, '/') != 0)
		return (0);
	while (m->path[++i] != NULL)
	{
		temp = ft_strjoin(m->path[i], "/");
		if (!temp)
			free_minishell(m, EXIT_FAILURE);
		cmd = ft_strjoin(temp, str);
		if (!cmd)
		{
			free(temp);
			free_minishell(m, EXIT_FAILURE);
		}
		free(temp);
		if (access(cmd, F_OK | X_OK) == 0)
			return (fill_path(m, cmd));
		free(cmd);
	}
	return (0);
}

int	is_cmd(t_minishell *m)
{
	int		i;
	char	*cmd;
	char	*temp;

	i = -1;
	if (m->path == NULL || ft_strchr(m->c->args[0], '/') != 0)
		return (0);
	while (m->path[++i] != NULL)
	{
		temp = ft_strjoin(m->path[i], "/");
		if (!temp)
			free_minishell(m, EXIT_FAILURE);
		cmd = ft_strjoin(temp, m->c->args[0]);
		if (!cmd)
		{
			free(temp);
			free_minishell(m, EXIT_FAILURE);
		}
		free(temp);
		if (access(cmd, F_OK | X_OK) == 0)
			return (fill_path(m, cmd));
		free(cmd);
	}
	return (0);
}
