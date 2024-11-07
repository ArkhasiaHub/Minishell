/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:39:30 by sbriche           #+#    #+#             */
/*   Updated: 2024/01/18 15:20:23 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr_gnl(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (i);
	return (-1);
}

char	*ft_strdup_nl(char const *s, int start, int len)
{
	char			*str;
	int				i;

	i = 0;
	str = (char *)malloc((len - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[start] && start < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup_gnl(const char *s)
{
	int		len;
	int		i;
	char	*dest;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_str_add(char *s1, char *s2, int size)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (s1);
	str = (char *) malloc(sizeof(char) * (ft_strlen_gnl(s1) + size + 1));
	if (!str)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && j < size)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
