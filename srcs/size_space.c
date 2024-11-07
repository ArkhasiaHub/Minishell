/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:03:14 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/07 10:31:56 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	increment_size(char *line, int i)
{
	if ((line[i] == '<' && line[i + 1] != '<'))
		return (1);
	if ((i == 0 && line[i] == '>') || (line[i] == '>' && line[i - 1] != '>'))
		return (1);
	if (line[i] == '|')
		return (1);
	return (0);
}

int	size_with_space(char *line)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (line[i])
	{
		if (increment_size(line, i) == 1)
			size += 2;
		i++;
		size++;
	}
	return (size);
}
