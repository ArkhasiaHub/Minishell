/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:25:35 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/11 10:43:58 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char	*find_line(char *str);
static int	stash_update(char (*stash)[BUFFER_SIZE + 1], char **str);
static char	*reading_file(int fd, char (*stash)[BUFFER_SIZE + 1], char **str);

char	*get_next_line(int fd)
{
	static char		stash[BUFFER_SIZE + 1];
	char			*str;

	str = NULL;
	if (fd < 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
	{
		stash[0] = '\0';
		return (NULL);
	}
	if (stash[0] != '\0')
	{
		if (stash_update(&stash, &str) == 0)
			return (NULL);
	}
	return (reading_file(fd, &stash, &str));
}

static char	*find_line(char *str)
{
	char	*line;	

	if (ft_strchr_gnl(str, '\n') == -1)
		line = ft_strdup_gnl(str);
	else
		line = ft_strdup_nl(str, 0, ft_strchr_gnl(str, '\n') + 1);
	free(str);
	if (!line)
		return (NULL);
	return (line);
}

static int	stash_update(char (*stash)[BUFFER_SIZE + 1], char **str)
{
	int	i;
	int	j;

	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if (!((*stash)[i] == '\n' && (*stash)[i + 1] == '\0'))
	{
		i++;
		*str = ft_str_add(*str, &(*stash)[i], BUFFER_SIZE - i);
		if (!(*str))
			return (0);
		j = 0;
		while (i < BUFFER_SIZE)
			(*stash)[j++] = (*stash)[i++];
		(*stash)[j] = '\0';
	}
	return (1);
}

static char	*reading_file(int fd, char (*stash)[BUFFER_SIZE + 1], char **str)
{
	char	*temp;
	int		char_read;

	char_read = -1;
	while (ft_strchr_gnl(*str, '\n') == -1)
	{
		char_read = read(fd, (*stash), BUFFER_SIZE);
		if (char_read == 0)
		{
			temp = find_line(*str);
			(*stash)[0] = '\0';
			return (temp);
		}
		if (char_read == -1)
			return (NULL);
		(*stash)[char_read] = '\0';
		*str = ft_str_add(*str, (*stash), char_read);
		if (!(*str))
			return (NULL);
	}
	temp = find_line(*str);
	return (temp);
}
