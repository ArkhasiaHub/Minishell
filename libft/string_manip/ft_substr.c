/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:12:54 by sbriche           #+#    #+#             */
/*   Updated: 2023/12/20 11:37:38 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string_manip.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	final_len;
	char	*str;

	if (!s)
		return (NULL);
	final_len = 0;
	if (ft_strlen(s) < 1 || ft_strlen(s) < start)
		return (ft_calloc(1, sizeof(char)));
	if (start + len + 1 > ft_strlen(s))
		final_len = ft_strlen(s) - start;
	while (final_len < len && s[start + final_len])
		final_len++;
	str = ft_calloc(final_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < final_len)
	{
		str[i] = s[i + start];
		i++;
	}
	return (str);
}
