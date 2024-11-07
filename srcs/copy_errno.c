/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_errno.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:41:49 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/08 14:46:43 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	copy_errno(int *j, char *dst, t_minishell *m)
{
	char	*temp;
	int		k;

	k = 0;
	temp = ft_itoa(g_status_signal);
	if (!temp)
		return (-1);
	while (temp[k])
	{
		dst[*j] = temp[k];
		k++;
		*j = *j + 1;
	}
	m->i = m->i + 2;
	return (0);
}
