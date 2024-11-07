/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:16:14 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/11 09:46:04 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_unset(char *line, char **unset);
static char	**create_new_env(char **envp, int len, t_vector_int *tab);
static int	strlen_token(char *s, int c);

void	unset_builtins(t_minishell *shell, char **unset)
{
	char			**tmp;
	int				i;
	int				len;
	t_vector_int	tab;

	if (!unset)
		return ;
	i = -1;
	tab.size = 0;
	tab.arr = NULL;
	len = ft_splitlen(shell->envp);
	while (shell->envp[++i])
	{
		if (check_unset(shell->envp[i], unset))
			resize_tab(&tab, i);
	}
	if (tab.arr != NULL)
	{
		tmp = create_new_env(shell->envp, len, &tab);
		if (shell->envp)
			free_split(shell->envp);
		shell->envp = tmp;
		update_path(shell);
		free(tab.arr);
	}
}

static int	check_unset(char *line, char **unset)
{
	int		i;
	int		tmp;
	int		tmp2;

	i = 0;
	tmp = strlen_token(line, '=');
	while (unset[i])
	{
		tmp2 = strlen_token(unset[i], '=');
		if ((ft_strncmp(line, unset[i], ft_strlen(unset[i])) == 0) && \
			(tmp == tmp2))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static char	**create_new_env(char **envp, int len, t_vector_int *tab)
{
	char	**new_env;
	int		i;
	int		j;

	new_env = ft_calloc(len + 1, sizeof(char *));
	if (!new_env)
		return (NULL);
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (check_tab(i, tab) == 0)
		{
			new_env[j] = ft_strdup(envp[i]);
			if (!new_env[j])
				return (NULL);
			j++;
		}
		i++;
	}
	return (new_env);
}

static int	strlen_token(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}
