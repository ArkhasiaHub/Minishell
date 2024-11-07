/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:57:29 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/07 10:58:15 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (1);
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_quote(char c, int quote)
{
	if (c == '"' || c == '\'')
	{
		if (quote == 0)
			return (1);
		else
			return (0);
	}
	return (quote);
}
