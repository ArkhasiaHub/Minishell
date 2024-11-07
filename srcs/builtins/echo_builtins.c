/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:35:24 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/11 10:51:07 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	check_flag(char **str, int *is_flag, int *i, int *j);

void	echo_str(int outfile, char **str, bool flag, int len)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		write(outfile, str[i], ft_strlen(str[i]));
		if ((i < len - 1 && !flag) || (i < len - 2 && flag))
			write(outfile, " ", 1);
	}
	if (!flag)
		write(outfile, "\n", 2);
}

void	ft_echo(int outfile, char **args, int len)
{
	char	**str;
	int		is_flag;
	int		i;
	int		j;

	if (len == 1)
	{
		write(outfile, "\n", 1);
		g_status_signal = 0;
		return ;
	}
	is_flag = 0;
	str = args + 1;
	i = 0;
	j = 0;
	check_flag(str, &is_flag, &i, &j);
	echo_str(outfile, str + i, is_flag, len - 1);
	g_status_signal = 0;
	return ;
}

static void	check_flag(char **str, int *is_flag, int *i, int *j)
{
	while (str[*i])
	{
		if (ft_strncmp(str[*i], "-n", 2) == 0)
			*is_flag = 1;
		else
			break ;
		*j = 1;
		while (*is_flag && str[*i][*j] && str[*i][*j] == 'n')
			(*j) += 1;
		if (str[*i][*j] != '\0')
		{
			if (*i == 0)
				*is_flag = 0;
			break ;
		}
		(*i) += 1;
	}
}
