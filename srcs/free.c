/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:15:43 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/11 10:17:11 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_splitn(char **split, int n)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (i < n)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_minishell(t_minishell *shell, int exit_status)
{
	if (shell->envp)
		free_splitn(shell->envp, ft_splitlen(shell->envp));
	if (shell->hard_envp)
		free_splitn(shell->hard_envp, ft_splitlen(shell->hard_envp));
	if (shell->c)
		free_commands(shell->c);
	if (shell->line)
		free(shell->line);
	free_split(shell->path);
	if (shell->prompt)
		free(shell->prompt);
	if (shell->pwd)
		free(shell->pwd);
	rl_clear_history();
	write(1, "\n", 1);
	exit(exit_status);
}

void	free_commands(t_commands *c)
{
	t_commands	*tmp;

	while (c)
	{
		tmp = c->next;
		c->previous = NULL;
		free_split(c->args);
		if (c->here_doc)
			free(c->here_doc);
		if (c->path)
			free(c->path);
		free(c);
		c = tmp;
	}
}

void	free_node(char ***node)
{
	int	i;

	i = 0;
	if (node)
	{
		while (node[i] != NULL)
		{
			free_split(node[i]);
			i++;
		}
		free(node);
	}
}
