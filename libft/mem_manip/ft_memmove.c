/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:15:33 by sbriche           #+#    #+#             */
/*   Updated: 2023/12/20 11:38:15 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mem_manip.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*temp_src;
	char			*temp_dest;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp_src = (char *)src;
	temp_dest = (char *)dest;
	if (temp_dest - temp_src > 0)
	{
		while (n-- > 0)
			temp_dest[n] = temp_src[n];
	}
	else
	{
		while (n-- > 0)
			*(temp_dest++) = *(temp_src++);
	}
	return (dest);
}
