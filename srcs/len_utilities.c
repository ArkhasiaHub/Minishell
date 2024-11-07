/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:14:41 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/07 10:32:08 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	splitlen(char **splited)
{
	int	i;

	i = 0;
	if (splited)
	{
		while (splited[i] != NULL && ft_strncmp(splited[i], "|", 2) != 0)
			i++;
		return (i);
	}
	return (0);
}

int	total_size(char **splited)
{
	int	i;

	i = 0;
	while (splited[i] != NULL)
		i++;
	return (i);
}

int	node_len(char **splited)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (splited[i] != NULL)
	{
		if (ft_strncmp(splited[i], "|", 2) == 0)
			count++;
		i++;
	}
	return (count + 1);
}
