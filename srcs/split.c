/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:01:40 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/07 11:04:45 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	create_split(char const *s, char *sep)
{
	int	i;
	int	count;
	int	quote;

	i = -1;
	count = 0;
	quote = 0;
	while (s[++i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			if (quote == 0)
				quote = 1;
			else
				quote = 0;
		}
		if (s[i + 1] != '\0' && is_sep(s[i], sep) == 0 \
			&& is_sep(s[i + 1], sep) == 1 && quote == 0)
			count++;
	}
	return (count + 1);
}

void	write_str(char *str, char const *s, char *sep, int index)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (is_sep(s[index], sep) == 0 || (is_sep(s[index], sep) == 1 \
		&& quote == 1 && s[index] != '\0'))
	{
		str[i] = s[index];
		quote = is_quote(s[index], quote);
		index++;
		i++;
	}
	str[i] = '\0';
}

void	find_word(int var[4], char **splited, char *sep, char *str)
{
	var[3] = is_quote(str[var[0]], var[3]);
	if (is_sep(str[var[0]], sep) == 1 && var[3] == 0)
		var[2] = var[0] + 1;
	if (is_sep(str[var[0]], sep) == 0 && is_sep(str[var[0] + 1], sep) == 1 \
		&& (var[3] == 0 || str[var[0] + 1] == '\0'))
	{
		splited[var[1]] = ft_calloc(var[0] - var[2] + 2, sizeof(char));
		if (!(splited[var[1]]))
			return (free_split(splited));
		write_str(splited[var[1]++], str, sep, var[2]);
	}
}

char	**quote_split(char *str, char *sep)
{
	char	**splited;
	int		var[4];

	var[0] = -1;
	var[1] = 0;
	var[2] = 0;
	var[3] = 0;
	splited = NULL;
	splited = ft_calloc((create_split(str, sep) + 1), sizeof(char *));
	if (!splited)
		return (NULL);
	while (str[++var[0]])
		find_word(var, splited, sep, str);
	splited[var[1]] = NULL;
	return (splited);
}
