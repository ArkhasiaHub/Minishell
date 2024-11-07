/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:29:18 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/11 10:50:33 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pars_error(t_minishell *m, char **splited, char ***node)
{
	free_split(splited);
	free_node(node);
	free_minishell(m, EXIT_FAILURE);
}

void	minishell(t_minishell *m)
{
	if (m->line[0] != '\0')
	{
		m->total_len = ft_strlen(m->line);
		add_history(m->line);
		if (parsing(m) == 0 && m->c)
		{
			begin_list(m);
			check_cmd(m);
			begin_list(m);
			if (SHOW == 1)
				show_commands(m->c);
			exec(m);
		}
		clean_minishell(m);
	}
	else
		free(m->line);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	m;

	(void)argc;
	(void)argv;
	init_minishell(&m, envp);
	update_path(&m);
	update_prompt(&m);
	m.c = NULL;
	while (1)
	{
		handling_signal(SIG_MAIN);
		m.line = NULL;
		m.line = readline(m.prompt);
		if (m.line == NULL)
		{
			write(1, "exit", 5);
			free_minishell(&m, 0);
		}
		minishell(&m);
	}
	free_split(m.envp);
}
