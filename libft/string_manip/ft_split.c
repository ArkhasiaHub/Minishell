/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:01:10 by sbriche           #+#    #+#             */
/*   Updated: 2023/12/20 11:37:05 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string_manip.h"

static int	is_charset(char s, char c)
{
	if (s == c || s == '\0')
		return (1);
	return (0);
}

static int	create_split(char const *s, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (is_charset(s[i], c) == 0 && is_charset(s[i + 1], c) == 1)
			count++;
	}
	return (count);
}

static char	**free_split(char **split, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(split[i]);
	free(split);
	return (NULL);
}

static void	write_str(char *str, char const *s, char c, int index)
{
	int	i;

	i = 0;
	while (is_charset(s[index], c) == 0)
	{
		str[i] = s[index];
		index++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		index;

	i = -1;
	j = 0;
	index = 0;
	split = (char **) malloc ((create_split(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (s[++i])
	{
		if (is_charset(s[i], c) == 1)
			index = i + 1;
		if (is_charset(s[i], c) == 0 && is_charset(s[i + 1], c) == 1)
		{
			split[j] = ft_calloc(i - index + 2, sizeof(char));
			if (!(split[j]))
				return (free_split(split, j));
			write_str(split[j++], s, c, index);
		}
	}
	split[j] = NULL;
	return (split);
}
