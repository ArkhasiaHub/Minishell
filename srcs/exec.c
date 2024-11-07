/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:56:38 by sbriche           #+#    #+#             */
/*   Updated: 2024/03/11 09:33:03 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	select_builtins(t_minishell *m, t_commands *c, char **tmp, int len);

int	exec(t_minishell *m)
{
	if (m->c->is_builtins == true && m->c->next == NULL)
		exec_builtins(m, m->c);
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		exec_cmds(m, m->c);
	}
	return (0);
}

void	exec_builtins(t_minishell *m, t_commands *cmds)
{
	char	**tmp;
	int		len;

	tmp = NULL;
	if (cmds->next != NULL && cmds->next->is_builtins)
		return ;
	len = ft_splitlen(cmds->args);
	if (len > 1)
		tmp = cpy_split(cmds->args + 1);
	select_builtins(m, cmds, tmp, len);
	if (tmp)
		free_split(tmp);
}

static int	select_builtins(t_minishell *m, t_commands *c, char **tmp, int len)
{
	if (c->builtins == FT_ECHO)
		ft_echo(1, c->args, len);
	else if (c->builtins == CD)
		cd(m, c->args);
	else if (c->builtins == ENV)
		env_builtins(m, c, 1, len);
	else if (c->builtins == EXPORT)
	{
		if (len == 1)
			export_show_builtins(m->envp, 1);
		else
			export_builtins(m, tmp);
	}
	else if (c->builtins == PWD)
		pwd(m, len, 1);
	else if (c->builtins == UNSET)
		unset_builtins(m, tmp);
	else if (c->builtins == EXIT)
		exit_builtins(m, tmp, len);
	return (1);
}
