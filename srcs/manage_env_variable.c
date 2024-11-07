/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_env_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:33:48 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/08 17:10:55 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_variable(char **envp, char *str)
{
	int		i;
	char	*temp;
	char	*temp2;
	char	*temp3;

	i = 0;
	temp = NULL;
	temp2 = NULL;
	temp3 = ft_strjoin(str, "=");
	if (envp != NULL && envp[i] != NULL)
	{
		while (envp[i] && ft_strncmp(envp[i], temp3, ft_strlen(temp3)) != 0)
			i++;
		if (envp[i] != NULL)
		{
			temp = ft_strdup(envp[i]);
			temp2 = ft_strdup(temp + ft_strlen(str) + 1);
			free(temp);
		}
		free(temp3);
		return (temp2);
	}
	return (NULL);
}

char	*copy_env_var(t_minishell *m, char *str)
{
	char	*ret;

	if (str[1] == '?')
	{
		ret = ft_itoa(g_status_signal);
		if (!ret)
			return (NULL);
		return (ret);
	}
	str = str + 1;
	ret = get_env_variable(m->envp, str);
	if (!ret)
		return (ft_strdup("\n"));
	return (ret);
}

char	*copy_normal_and_env(t_minishell *m, char *str)
{
	int		i;
	int		j;
	char	*temp;
	char	*temp2;
	char	*temp3;

	i = 0;
	j = 0;
	while (str[i] != '$')
		i++;
	while (str[j])
		j++;
	temp = ft_substr(str, 0, i);
	temp2 = ft_substr(str, i + 1, j - (i + 1));
	temp3 = get_env_variable(m->envp, temp2);
	if (!temp3)
		temp3 = ft_strdup("\0");
	free(temp2);
	temp2 = ft_strjoin(temp, temp3);
	free(temp);
	free(temp3);
	return (temp2);
}
