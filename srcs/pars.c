/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:47:18 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/08 14:47:58 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	clean_parse(t_minishell *m, int n, char *s);

int	pars_infile(t_minishell *m, char ***node, int j, int i)
{
	char	*infile;

	if (!node[j][i + 1])
		return (clean_parse(m, 0, NULL));
	if (is_operator(node[j][i + 1]) == 1)
		return (clean_parse(m, 1, node[j][i + 1]));
	else
	{
		if (m->c->infile != 0)
			close(m->c->infile);
		infile = quote_strdup(node[j][i + 1], search_quote(node[j][i + 1]));
		if (access(infile, F_OK | R_OK) != 0)
		{
			perror(infile);
			g_status_signal = 1;
			free(infile);
			m->c->infile = -1;
			return (1);
		}
		m->c->token_l = INFILE;
		m->c->infile = open(infile, O_RDONLY);
		free(infile);
	}
	return (0);
}

int	pars_outfile(t_minishell *m, char ***node, int j, int i)
{
	char	*outfile;

	if (!node[j][i + 1])
		return (clean_parse(m, 0, NULL));
	if (is_operator(node[j][i + 1]) == 1)
		return (clean_parse(m, 1, node[j][i + 1]));
	else
	{
		if (m->c->outfile != 1)
			close(m->c->outfile);
		outfile = quote_strdup(node[j][i + 1], search_quote(node[j][i + 1]));
		if (access(outfile, F_OK) == 0 && access(outfile, W_OK) == -1)
		{
			perror(outfile);
			g_status_signal = 1;
			return (free(outfile), 1);
		}
		m->c->token_r = OUTFILE;
		m->c->outfile = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		free(outfile);
	}
	return (0);
}

int	pars_here_doc(t_minishell *m, char ***node, int j, int i)
{
	char	*tmp;

	if (!node[j][i + 1])
		return (clean_parse(m, 0, NULL));
	if (is_operator(node[j][i + 1]) == 1)
		return (clean_parse(m, 1, node[j][i + 1]));
	else
	{
		if (m->c->infile != 0)
			close(m->c->infile);
		if (m->tmp_heredoc)
			free(m->tmp_heredoc);
		tmp = generate_tmp_file();
		if (!tmp)
			return (-1);
		m->c->infile = open(tmp, O_CREAT | O_RDWR | O_TRUNC, 0666);
		m->c->token_l = HERE_DOC;
		m->c->here_doc = quote_strdup(node[j][i + 1], \
			search_quote(node[j][i + 1]));
		here_doc(m);
		close(m->c->infile);
		m->tmp_heredoc = tmp;
		m->c->infile = open(tmp, O_RDONLY);
	}
	return (0);
}

int	pars_append(t_minishell *m, char ***node, int j, int i)
{
	char	*outfile;

	if (!node[j][i + 1])
		return (clean_parse(m, 0, NULL));
	if (is_operator(node[j][i + 1]) == 1)
		return (clean_parse(m, 1, node[j][i + 1]));
	else
	{
		if (m->c->outfile != 1)
			close(m->c->outfile);
		outfile = quote_strdup(node[j][i + 1], search_quote(node[j][i + 1]));
		if (access(outfile, F_OK) == 0 && access(outfile, W_OK) == -1)
		{
			perror(outfile);
			g_status_signal = 1;
			return (free(outfile), 1);
		}
		m->c->token_r = OUTFILE;
		m->c->outfile = open(outfile, O_CREAT | O_WRONLY | O_APPEND, 0666);
		free(outfile);
	}
	return (0);
}

static int	clean_parse(t_minishell *m, int n, char *s)
{
	if (n == 0)
		printf("minishell : syntax error near unexpected token `newline'\n");
	else
		printf("minishell : syntax error near unexpected token `%s'\n", s);
	clean_minishell(m);
	return (-1);
}
