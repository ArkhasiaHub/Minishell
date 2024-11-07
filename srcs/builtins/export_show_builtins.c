/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_show_builtins.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:19:49 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/08 14:14:36 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sort_export(char **envp);

int	export_show_builtins(char **envp, int outfile)
{
	char	**tmp;
	int		i;

	if (!envp)
		return (-1);
	tmp = cpy_split(envp);
	sort_export(tmp);
	i = 0;
	while (tmp[i])
	{
		write(outfile, tmp[i], ft_strlen(tmp[i]));
		write(outfile, "\n", 1);
		i++;
	}
	free_split(tmp);
	return (0);
}

static int	sort_export(char **envp)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (envp[i])
	{
		j = i;
		while (envp[j])
		{
			if (ft_strncmp(envp[i], envp[j], ft_strlen(envp[j])) > 0)
			{
				tmp = ft_strdup(envp[i]);
				tmp2 = ft_strdup(envp[j]);
				free(envp[i]);
				free(envp[j]);
				envp[j] = tmp;
				envp[i] = tmp2;
			}
			j++;
		}
		i++;
	}
	return (0);
}
