/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_tmp_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:16:42 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/05 10:54:34 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	generate_name(char *buff, const char *base);
static int	is_base(int c, const char *base);

char	*generate_tmp_file(void)
{
	char	*buff;
	char	*tmp;

	tmp = ft_calloc(7, sizeof(char));
	if (!tmp)
		return (NULL);
	if (!generate_name(tmp, "abcdef0123456789"))
		return (free(tmp), NULL);
	buff = ft_strjoin(".", tmp);
	free(tmp);
	return (buff);
}

static int	generate_name(char *buff, const char *base)
{
	char	tmp[6];
	int		fd;
	int		i;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (i < 6)
	{
		if (read(fd, tmp, 1) == -1)
			return (0);
		if (!is_base(tmp[0], base))
			continue ;
		buff[i] = tmp[0];
		i++;
	}
	return (1);
}

static int	is_base(int c, const char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}
