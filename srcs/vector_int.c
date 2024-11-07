/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:17:37 by sbriche           #+#    #+#             */
/*   Updated: 2024/02/16 10:57:00 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	resize_tab(t_vector_int *tab, int index)
{
	int	i;
	int	*cpy;

	tab->size += 1;
	cpy = ft_calloc(tab->size, sizeof(int));
	if (!cpy)
		return (1);
	i = -1;
	while (++i < tab->size - 1)
		cpy[i] = tab->arr[i];
	if (tab->arr)
		free(tab->arr);
	cpy[i] = index;
	tab->arr = cpy;
	return (0);
}

int	check_tab(int index, t_vector_int *tab)
{
	int	i;

	i = -1;
	while (++i < tab->size)
	{
		if (index == tab->arr[i])
			return (1);
	}
	return (0);
}
