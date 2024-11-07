/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:27:54 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/07 15:58:57 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_commands(t_commands *c)
{
	int	i;

	i = 0;
	while (c != NULL)
	{
		while (c->args[i])
		{
			printf("args[%d] = %s\n", i, c->args[i]);
			i++;
		}
		printf("next = %p\n", c->next);
		printf("path = %s\n", c->path);
		printf("infile : %d -- outfile : %d\n", c->infile, c->outfile);
		printf("builtins = %d\n", c->builtins);
		printf("is_builtins = %d\n\n", c->is_builtins);
		c = c->next;
		i = 0;
	}
}
