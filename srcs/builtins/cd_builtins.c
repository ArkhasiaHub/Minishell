/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:16:41 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/08 14:33:02 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	verif_args(t_minishell *shell, char **path);
static int	cd_home(t_minishell *shell);
static int	go_home(t_minishell *shell, char *tmp);

void	cd(t_minishell *shell, char **path)
{
	char	*tmp;
	char	*pwd;
	char	c[2048];

	if (verif_args(shell, path))
		return ;
	if (chdir(path[1]) == -1)
		perror(path[1]);
	else
	{
		pwd = getcwd(c, sizeof(c));
		if (pwd == NULL)
			free_minishell(shell, 1);
		tmp = ft_strdup(pwd);
		if (!tmp)
			return (free_minishell(shell, 1));
		free(shell->pwd);
		shell->pwd = tmp;
		update_prompt(shell);
	}
}

static int	verif_args(t_minishell *shell, char **path)
{
	int	len;

	len = ft_splitlen(path);
	if (len == 1)
		return (cd_home(shell));
	if (len > 2)
	{
		write(1, "too many arguments\n", 20);
		return (1);
	}
	return (0);
}

static int	cd_home(t_minishell *shell)
{
	int		i;
	char	*tmp;

	i = 0;
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], "HOME=", 5) == 0)
			break ;
		i++;
	}
	if (shell->envp[i] == NULL)
	{
		write(1, "HOME not set\n", 14);
		return (1);
	}
	tmp = ft_strchr(shell->envp[i], '=') + 1;
	return (go_home(shell, tmp));
}

static int	go_home(t_minishell *shell, char *tmp)
{
	char	*pwd;
	char	*tmp2;
	char	c[2048];

	if (chdir(tmp) == -1)
		free_minishell(shell, 1);
	else
	{
		pwd = getcwd(c, sizeof(c));
		if (pwd == NULL)
			free_minishell(shell, 1);
		else
		{
			tmp2 = ft_strdup(pwd);
			if (!tmp2)
				free_minishell(shell, 1);
			free(shell->pwd);
			shell->pwd = tmp2;
			update_prompt(shell);
		}
	}
	return (1);
}
