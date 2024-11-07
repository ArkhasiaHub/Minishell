/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:49:07 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/08 09:27:16 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_value(int (*k)[4], char ***splited, char ****node);
static void	create_node(t_minishell *m, char ****node, int k, char **splited);
static void	in_loop(t_minishell *m, char ****node, char **splited, int (*k)[4]);

int	parsing(t_minishell *m)
{
	int		k[4];
	char	**splited;
	char	***node;

	init_value(&k, &splited, &node);
	copy_with_space(m);
	splited = quote_split(m->line, " \t");
	if (!splited)
		free_minishell(m, EXIT_FAILURE);
	k[3] = node_len(splited);
	create_node(m, &node, k[3], splited);
	while (++k[2] < m->total_len)
	{
		in_loop(m, &node, splited, &k);
		node[k[1]][k[0]] = NULL;
		k[1]++;
		k[0] = -1;
		if (splited[k[2]])
			free(splited[k[2]]);
	}
	node[k[1]] = NULL;
	free(splited);
	if (fill_list(m, node) == -1)
		return (-1);
	return (free_node(node), 0);
}

static void	in_loop(t_minishell *m, char ****node, char **splited, int (*k)[4])
{
	(*k)[3] = splitlen(splited + (*k)[2]);
	(*node)[(*k)[1]] = ft_calloc(sizeof(char *), (*k)[3] + 1);
	if (!(*node)[(*k)[1]])
		pars_error(m, splited, *node);
	while (++(*k)[0] < (*k)[3])
	{
		(*node)[(*k)[1]][(*k)[0]] = ft_strdup(splited[(*k)[2]]);
		free(splited[(*k)[2]]);
		if (!(*node)[(*k)[1]][(*k)[0]])
			pars_error(m, splited, *node);
		(*k)[2]++;
	}
}

static void	create_node(t_minishell *m, char ****node, int k, char **splited)
{
	*node = malloc(sizeof(char **) * (k + 1));
	if (!(*node))
	{
		free_split(splited);
		free_minishell(m, EXIT_FAILURE);
	}
	m->total_len = total_size(splited);
}

static void	init_value(int (*k)[4], char ***splited, char ****node)
{
	(*k)[0] = -1;
	(*k)[1] = 0;
	(*k)[2] = -1;
	*splited = NULL;
	*node = NULL;
}
