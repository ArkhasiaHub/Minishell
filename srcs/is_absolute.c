/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:25:04 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/07 12:25:32 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_absolute_one(char *str)
{
	if (access(str, F_OK | X_OK) == 0)
		return (1);
	return (0);
}

int	is_absolute(t_minishell *m)
{
	if (access(m->c->args[0], F_OK | X_OK) == 0)
		return (1);
	return (0);
}
