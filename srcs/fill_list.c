/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:17:41 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/08 16:51:14 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_fill(t_minishell *m, char ***node)
{
	free_node(node);
	free_minishell(m, EXIT_FAILURE);
}

void	fill_env_variable(t_minishell *m, char ***node, char **temp, int var[3])
{
	m->c->args[var[2]] = copy_env_var(m, node[var[0]][var[1]]);
	if (var[2] == 0)
	{
		temp = ft_split(m->c->args[var[2]], ' ');
		if (!temp)
			error_fill(m, node);
		if (check_one(m, temp[0]) == 1)
		{
			free_split(m->c->args);
			m->c->args = cpy_split(temp);
			free(temp);
		}
		free_split(temp);
	}
	if (!m->c->args[var[2]])
		error_fill(m, node);
}

int	no_quote_or_operator(t_minishell *m, int var[3], char ***node)
{
	char	**temp;

	temp = NULL;
	if (node[var[0]][var[1]][0] == '$')
		fill_env_variable(m, node, temp, var);
	else if (ft_strchr(node[var[0]][var[1]], '$') != NULL)
	{
		m->c->args[var[2]] = copy_normal_and_env(m, node[var[0]][var[1]]);
		if (!m->c->args[var[2]])
			error_fill(m, node);
	}
	else
	{
		m->c->args[var[2]] = ft_strdup(node[var[0]][var[1]]);
		if (!m->c->args[var[2]])
			error_fill(m, node);
	}
	var[1]++;
	var[2]++;
	return (var[2]);
}

int	fill(t_minishell *m, char ***node, int var[3])
{
	int	op;

	op = pars_operator(m, node, var[1], var[0]);
	if (op == -1)
		return (-1);
	if (op == 1)
		var[1] += 2;
	else
	{
		op = manage_quote(m, node[var[0]][var[1]], &var[1], &var[2]);
		if (op == -1)
		{
			free_node(node);
			clean_minishell(m);
			return (-1);
		}
		if (op == 0)
			no_quote_or_operator(m, var, node);
	}
	return (0);
}

int	fill_list(t_minishell *m, char ***node)
{
	int	var[3];

	var[0] = -1;
	while (node[++var[0]])
	{
		var[1] = 0;
		var[2] = 0;
		if (add_node(m) == -1)
		{
			free_node(node);
			free_minishell(m, EXIT_FAILURE);
		}
		m->c->args = ft_calloc(sizeof(char *), splitlen(node[var[0]]) + 1);
		if (!m->c->args)
		{
			free_node(node);
			free_minishell(m, EXIT_FAILURE);
		}
		while (node[var[0]][var[1]])
		{
			if (fill(m, node, var) == -1)
				return (-1);
		}
	}
	return (0);
}
