/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:44:42 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/11 09:54:59 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*init_val(t_minishell *m, char *str, int *k, int *n);

int	manage_env_variable(t_minishell *m, int *len, char *str)
{
	int		j;
	char	*temp;
	char	*variable;

	m->i = m->i + 1;
	j = m->i;
	while (str[j] != '"' && str[j] != '\'' && str[j] != '\0')
		j++;
	temp = ft_substr(str, m->i, j - m->i);
	if (!temp)
		return (-1);
	if (ft_strncmp(temp, "?", 2) == 0)
		*len = *len + 3;
	else
	{
		variable = get_env_variable(m->envp, temp);
		if (!variable)
			variable = ft_strdup("\0");
		*len = *len + ft_strlen(variable);
	}
	free(temp);
	return (free(variable), 0);
}

int	copy_env_variable(t_minishell *m, int *j, char *str, char *dst)
{
	int		k;
	char	*temp;
	char	*variable;
	int		n;

	temp = init_val(m, str, &k, &n);
	if (!temp)
		return (-1);
	if (ft_strncmp(temp, "?", 2) == 0)
		return (1);
	else
	{
		variable = get_env_variable(m->envp, temp);
		if (!variable)
			variable = ft_strdup("\0");
	}
	free(temp);
	m->i = k - 1;
	while (variable[n])
	{
		dst[*j] = variable[n];
		n++;
		*j = *j + 1;
	}
	return (free(variable), 0);
}

static char	*init_val(t_minishell *m, char *str, int *k, int *n)
{
	char	*temp;

	m->i = m->i + 1;
	*k = m->i;
	*n = 0;
	while (str[*k] != '"' && str[*k] != '\'' && str[*k] != '\0')
		(*k) += 1;
	temp = ft_substr(str, m->i, (*k) - m->i);
	return (temp);
}
