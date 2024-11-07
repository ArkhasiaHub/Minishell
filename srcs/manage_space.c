/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:48:37 by earaujo           #+#    #+#             */
/*   Updated: 2024/02/19 17:13:06 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	manage_space_in(t_minishell *m, int i, int j, char *temp)
{
	temp[j] = ' ';
	j++;
	temp[j] = m->line[i];
	j++;
	i++;
	temp[j] = ' ';
	j++;
	return (j);
}

int	manage_space_out(t_minishell *m, int i, int j, char *temp)
{
	temp[j] = ' ';
	j++;
	temp[j] = m->line[i];
	j++;
	i++;
	temp[j] = ' ';
	j++;
	return (j);
}

int	manage_space_app(t_minishell *m, int i, int j, char *temp)
{
	temp[j] = ' ';
	j++;
	temp[j] = m->line[i];
	j++;
	i++;
	temp[j] = m->line[i];
	j++;
	i++;
	temp[j] = ' ';
	j++;
	return (j);
}

int	manage_space_here_doc(t_minishell *m, int i, int j, char *temp)
{
	temp[j] = ' ';
	j++;
	temp[j] = m->line[i];
	j++;
	i++;
	temp[j] = m->line[i];
	j++;
	i++;
	temp[j] = ' ';
	j++;
	return (j);
}

int	manage_space_pipe(t_minishell *m, int i, int j, char *temp)
{
	temp[j] = ' ';
	j++;
	temp[j] = m->line[i];
	j++;
	i++;
	temp[j] = ' ';
	j++;
	return (j);
}
