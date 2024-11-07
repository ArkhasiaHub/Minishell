/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:22:39 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/11 09:43:27 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	update_prompt(t_minishell *shell)
{
	char	*prompt;
	char	*temp;

	if (shell->prompt)
		free(shell->prompt);
	shell->prompt = NULL;
	temp = ft_strjoin("minishell : ", shell->pwd);
	if (!temp)
		return (-1);
	prompt = ft_strjoin(temp, "$ ");
	free(temp);
	if (!prompt)
		return (-1);
	shell->prompt = prompt;
	return (0);
}

int	update_path(t_minishell *m)
{
	char	*temp;

	temp = get_env_variable(m->envp, "PATH");
	if (temp)
	{
		if (m->path)
		{
			free_split(m->path);
			m->path = NULL;
		}
		m->path = ft_split(temp, ':');
		if (!m->path)
			exit(EXIT_FAILURE);
	}
	else
	{
		if (m->path)
		{
			free_split(m->path);
			m->path = NULL;
		}
	}
	free(temp);
	return (0);
}
