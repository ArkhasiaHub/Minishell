/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:12:05 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/06 16:14:16 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pars_operator(t_minishell *m, char ***node, int i, int j)
{
	if (ft_strncmp(node[j][i], "<", 2) == 0)
	{
		if (pars_infile(m, node, j, i) == -1)
			return (-1);
		return (1);
	}
	else if (ft_strncmp(node[j][i], ">", 2) == 0)
	{
		if (pars_outfile(m, node, j, i) == -1)
			return (-1);
		return (1);
	}
	else if (ft_strncmp(node[j][i], "<<", 3) == 0)
	{
		if (pars_here_doc(m, node, j, i) == -1)
			return (-1);
		return (1);
	}
	else if (ft_strncmp(node[j][i], ">>", 2) == 0)
	{
		if (pars_append(m, node, j, i) == -1)
			return (-1);
		return (1);
	}
	return (0);
}
