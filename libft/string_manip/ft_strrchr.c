/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:15:34 by sbriche           #+#    #+#             */
/*   Updated: 2023/12/20 11:37:35 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string_manip.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (s[len] == (unsigned char)c)
		return (((char *)s) + len);
	while (len-- > 0)
	{
		if (s[len] == (unsigned char)c)
			return (((char *)s) + len);
	}
	return (0);
}
