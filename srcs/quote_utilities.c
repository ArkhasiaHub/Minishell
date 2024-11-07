/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:31:59 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/08 17:13:36 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	cpy_join(char *str, char *s2, int j, char c);
static char	*null_arg(char *s1, char *s2);

char	*quote_strjoin(char *s1, char *s2, char c)
{
	int		i;
	int		j;
	char	*str;
	int		size;
	char	*temp;

	temp = null_arg(s1, s2);
	if (temp != NULL)
		return (temp);
	size = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	str = ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
	{
		if (s1[i] != c)
			str[j] = s1[i];
		j++;
	}
	cpy_join(str, s2, j, c);
	return (str);
}

static char	*null_arg(char *s1, char *s2)
{
	char	*temp;

	if (!s1 && !s2)
		return ("\0");
	else if (!s1)
	{
		temp = ft_strdup((char *)s2);
		return (free((char *)s2), temp);
	}
	else if (!s2)
	{
		temp = ft_strdup((char *)s1);
		return (free((char *)s1), temp);
	}
	temp = NULL;
	return (temp);
}

static void	cpy_join(char *str, char *s2, int j, char c)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (s2[++i])
	{
		if (s2[i] != c)
		{
			str[k + j] = s2[i];
			k++;
		}
	}
	str[i + j] = '\0';
}

int	search_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != '"' && str[i] != '\''))
		i++;
	if (str[i] && (str[i] == '"' || str[i] == '\''))
		return (str[i]);
	else
		return (0);
}

char	*quote_strdup(char *src, int c)
{
	char	*s;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen(src);
	s = ft_calloc(sizeof(char), (len + 1));
	if (!s)
		return (NULL);
	while (src[i])
	{
		if (src[i] != c)
		{
			s[j] = src[i];
			j++;
		}
		i++;
	}
	s[j] = '\0';
	return (s);
}
