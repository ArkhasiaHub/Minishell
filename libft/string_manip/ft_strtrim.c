/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:13:29 by sbriche           #+#    #+#             */
/*   Updated: 2023/12/20 11:37:37 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string_manip.h"

static int	is_base(char c, char const *base)
{
	size_t	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	new_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	i = len;
	while (is_base(s1[--i], set) == 1)
		len--;
	i = 0;
	while (i <= len && is_base(s1[i], set) == 1)
	{
		i++;
		len--;
	}
	return (i);
}

static size_t	new_len(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	i = len;
	while (is_base(s1[--i], set) == 1)
		len--;
	i = 0;
	while (i <= len && is_base(s1[i], set) == 1)
	{
		i++;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;

	str = ft_substr(s1, new_start(s1, set), new_len(s1, set));
	return (str);
}
