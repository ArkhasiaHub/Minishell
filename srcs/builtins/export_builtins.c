/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:21:53 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/08 14:14:06 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_export(char **export, char **export_val, int len);
static int	check_envp(char *line, char **export, char **export_val, int len);
static char	**add_export(t_minishell *shell, char **export, int export_size);
static int	check_res(t_minishell *shell, char **new_envp);

int	export_builtins(t_minishell *shell, char **export)
{
	int				i;
	int				n;
	int				len;
	char			**export_val;

	if (!export)
		return (-1);
	len = ft_splitlen(export);
	export_val = ft_calloc(len + 1, sizeof(char *));
	if (!export_val)
		return (-1);
	n = check_export(export, export_val, len);
	i = -1;
	while (shell->envp[++i])
		n += check_envp(shell->envp[i], export, export_val, len);
	free(export_val);
	export_val = add_export(shell, export, len - n);
	return (check_res(shell, export_val));
}

static int	check_envp(char *line, char **export, char **export_val, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (export[i] == NULL)
			continue ;
		if (ft_strncmp(line, export[i], export_val[i] - export[i]) == 0)
		{
			free(line);
			line = ft_strdup(export[i]);
			if (!line)
				return (-1);
			export[i] = NULL;
			return (1);
		}
	}
	return (0);
}

static int	check_export(char **export, char **export_val, int len)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < len)
	{
		export_val[i] = ft_strchr(export[i], '=');
		if (export_val[i] == NULL)
		{
			free(export[i]);
			export[i] = NULL;
			n++;
		}
		i++;
	}
	return (n);
}

static char	**add_export(t_minishell *shell, char **export, int export_size)
{
	char	**new_envp;
	int		i;
	int		j;
	int		len;

	len = ft_splitlen(shell->envp);
	new_envp = ft_calloc(len + 1 + export_size, sizeof(char *));
	if (!new_envp)
		return (NULL);
	i = -1;
	while (++i < len)
		new_envp[i] = ft_strdup(shell->envp[i]);
	len += export_size;
	j = -1;
	while (i < len)
	{
		if (export[++j] == NULL)
			continue ;
		new_envp[i] = ft_strdup(export[j]);
		if (new_envp[i] == NULL)
			return (free_splitn(new_envp, i), NULL);
		i++;
	}
	return (new_envp);
}

static int	check_res(t_minishell *shell, char **new_envp)
{
	if (new_envp == NULL)
		return (-1);
	if (shell->envp)
		free_split(shell->envp);
	shell->envp = new_envp;
	return (0);
}
