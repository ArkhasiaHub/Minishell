/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:38:55 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/07 09:39:10 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(char *str)
{
	if (ft_strncmp(str, "<", 2) == 0)
		return (1);
	if (ft_strncmp(str, ">", 2) == 0)
		return (1);
	if (ft_strncmp(str, ">>", 3) == 0)
		return (1);
	if (ft_strncmp(str, "<<", 3) == 0)
		return (1);
	return (0);
}
