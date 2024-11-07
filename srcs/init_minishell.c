/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:50:39 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/08 17:05:13 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_shlvl(t_minishell *shell);
static void	set_shell(t_minishell *shell);

void	init_minishell(t_minishell *shell, char **envp)
{
	char	*tmp;
	char	c[2048];

	shell->envp = NULL;
	if (envp != NULL || envp[0] != NULL)
	{
		shell->envp = cpy_split(envp);
		if (shell->envp == NULL)
			exit(EXIT_FAILURE);
	}
	if (envp != NULL && envp[0] != NULL && update_shlvl(shell) == -1)
	{
		free_split(shell->envp);
		exit(EXIT_FAILURE);
	}
	set_shell(shell);
	tmp = getcwd(c, sizeof(c));
	shell->pwd = ft_strdup(tmp);
	if (!shell->pwd)
	{
		free_split(shell->envp);
		exit(EXIT_FAILURE);
	}
}

static void	set_shell(t_minishell *shell)
{
	shell->hard_envp = NULL;
	shell->tmp_heredoc = NULL;
	shell->c = NULL;
	g_status_signal = 0;
	shell->line = NULL;
	shell->path = NULL;
	shell->prompt = NULL;
	shell->quote = 0;
	shell->splited_line = NULL;
	shell->total_len = 0;
}

static int	update_shlvl(t_minishell *shell)
{
	char	*res;
	int		i;
	int		val;
	char	*temp;

	i = 0;
	if (!shell->envp)
		return (0);
	while (shell->envp && shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], "SHLVL=", 6) == 0)
			break ;
		i++;
	}
	temp = ft_strchr(shell->envp[i], '=');
	temp++;
	val = ft_atoi(temp) + 1;
	temp = ft_itoa(val);
	res = ft_strjoin("SHLVL=", temp);
	free(temp);
	if (!res)
		return (-1);
	free(shell->envp[i]);
	shell->envp[i] = res;
	return (0);
}
