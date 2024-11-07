/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:33:51 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/01 10:16:02 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**cpy_split(char **src)
{
	char		**dst;
	int			i;
	int			len;

	i = 0;
	len = ft_splitlen(src);
	dst = ft_calloc(len + 1, sizeof(char *));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = ft_strdup(src[i]);
		if (!dst[i])
		{
			free_splitn(dst, i);
			return (NULL);
		}
		i++;
	}
	return (dst);
}
