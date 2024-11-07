/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:05:17 by earaujo           #+#    #+#             */
/*   Updated: 2024/03/11 09:32:51 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/conversion.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/is_type.h"
# include "../libft/includes/list.h"
# include "../libft/includes/mem_manip.h"
# include "../libft/includes/string_manip.h"
# include "../libft/includes/vector.h"
# include "../libft/includes/write.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <signal.h>

# ifndef SHOW
#  define SHOW 0
# endif

extern int	g_status_signal;

typedef enum e_quote
{
	NONE,
	SIMPLE = '\'',
	DOUBLE = '"',
}	t_quote;

typedef enum e_type
{
	WORD,
	INFILE,
	OUTFILE,
	HERE_DOC,
	APPEND,
}	t_type;

typedef enum e_sig
{
	SIG_MAIN,
	SIG_CHILD,
	SIG_PARENT,
	SIG_HEREDOC
}	t_sig;

typedef enum e_builtins
{
	FT_ECHO = 1,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
}	t_builtins;

typedef enum e_pipe
{
	RD,
	WR,
	MAX_PIPE
}	t_pipe;

typedef struct s_commands
{
	bool				is_builtins;
	int					builtins;
	char				*path;
	char				**args;
	t_type				token_l;
	t_type				token;
	t_type				token_r;
	int					infile;
	int					outfile;
	char				*here_doc;
	pid_t				pid;
	struct s_commands	*next;
	struct s_commands	*previous;
}	t_commands;

typedef struct s_vector_int
{
	int	*arr;
	int	size;
}	t_vector_int;

typedef struct s_minishell
{
	char		*prompt;
	char		*pwd;
	t_commands	*c;
	char		**splited_line;
	int			exit_status;
	char		**path;
	char		**envp;
	char		**hard_envp;
	char		*tmp_heredoc;
	char		*line;
	int			total_len;
	int			quote;
	int			i;
}	t_minishell;

void	free_splitn(char **split, int n);
int		ft_splitlen(char **split);
int		resize_tab(t_vector_int *tab, int index);
int		check_tab(int index, t_vector_int *tab);
void	free_minishell(t_minishell *shell, int exit_status);
char	**cpy_split(char **src);
void	free_split(char **split);
void	init_minishell(t_minishell *shell, char **envp);

void	cd(t_minishell *shell, char **path);
void	env_builtins(t_minishell *shell, t_commands *c, int outfile, int len);
void	exit_builtins(t_minishell *shell, char **args, int len);
void	pwd(t_minishell *shell, int argc, int outfile);
void	unset_builtins(t_minishell *shell, char **unset);
int		export_builtins(t_minishell *shell, char **export);
void	ft_echo(int outfile, char **args, int len);

int		update_prompt(t_minishell *shell);
int		update_path(t_minishell *m);
char	*generate_tmp_file(void);
int		list_size(t_commands *cmds);
void	wait_all_pids(t_commands *cmds);
int		exec(t_minishell *shell);
int		exec_cmds(t_minishell *shell, t_commands *cmds);
void	exec_builtins(t_minishell *shell, t_commands *cmds);
int		create_process(t_minishell *shell, t_commands *c, \
	char **envp, int to_close);
void	closing_fds(t_commands *c);
void	free_commands(t_commands *c);
void	clean_minishell(t_minishell *shell);
void	clean_list(t_minishell *m);
int		handling_signal(int m);
int		quote_len(t_minishell *m, char *str, int *len);
void	change_quote(char *str, t_minishell *m, int *quote);
int		manage_env_variable(t_minishell *m, int *len, char *str);
int		copy_env_variable(t_minishell *m, int *j, char *str, char *dst);
int		copy_new_string(char *str, char *dst, t_minishell *m);
int		copy_errno(int *j, char *dst, t_minishell *m);
int		count_quote(char *line, char c);
int		manage_space_here_doc(t_minishell *m, int i, int j, char *temp);
int		manage_space_app(t_minishell *m, int i, int j, char *temp);
int		manage_space_out(t_minishell *m, int i, int j, char *temp);
int		manage_space_in(t_minishell *m, int i, int j, char *temp);
int		manage_space_pipe(t_minishell *m, int i, int j, char *temp);
int		pars_infile(t_minishell *m, char ***node, int j, int i);
int		pars_outfile(t_minishell *m, char ***node, int j, int i);
int		pars_here_doc(t_minishell *m, char ***node, int j, int i);
int		pars_append(t_minishell *m, char ***node, int j, int i);
int		is_operator(char *str);
void	here_doc(t_minishell *m);
void	check_cmd(t_minishell *m);
int		total_size(char **splited);
void	free_split(char **splited);
char	**quote_split(char *str, char *sep);
int		manage_quote(t_minishell *m, char *str, int *i, int *k);
char	*quote_strjoin(char *s1, char *s2, char c);
void	free_node(char ***node);
int		search_quote(char *str);
char	*quote_strdup(char *src, int c);
char	*get_env_variable(char **envp, char *str);
int		export_show_builtins(char **envp, int outfile);
int		is_cmd_one(t_minishell *m, char *str);
int		is_absolute_one(char *str);
int		is_builtins_one(char *str);
int		check_one(t_minishell *m, char *str);
void	show_commands(t_commands *c);
char	*copy_env_var(t_minishell *m, char *str);
char	*copy_normal_and_env(t_minishell *m, char *str);
void	copy_with_space(t_minishell *m);
int		size_with_space(char *line);
int		pars_operator(t_minishell *m, char ***node, int i, int j);
int		total_size(char **splited);
int		node_len(char **splited);
int		splitlen(char **splited);
int		fill_list(t_minishell *m, char ***node);
int		add_node(t_minishell *m);
void	begin_list(t_minishell *m);
void	pars_error(t_minishell *m, char **splited, char ***node);
int		parsing(t_minishell *m);
int		is_sep(char c, char *sep);
int		is_quote(char c, int quote);
int		is_builtins(t_minishell *m);
int		is_environment_builtins(t_minishell *m);
int		is_absolute(t_minishell *m);
int		is_absolute_one(char *str);
int		is_cmd(t_minishell *m);
int		is_cmd_one(t_minishell *m, char *str);
void	set_process_handle(void);
void	set_process_child(void);
void	signal_handler(int sig);
void	set_process_child(void);

#endif
