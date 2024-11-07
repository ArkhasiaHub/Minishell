NAME = minishell

CC = cc

FLAGS = -Wall -Wextra -Werror -MMD -MP -I includes -g3

LIBFT = ./libft/libft.a

SRCS = ./srcs/minishell.c \
./srcs/check_cmd.c \
./srcs/split.c \
./srcs/manage_quotes.c \
./srcs/free.c \
./srcs/builtins/cd_builtins.c \
./srcs/builtins/env_builtins.c \
./srcs/builtins/exit_builtins.c \
./srcs/builtins/pwd_builtins.c \
./srcs/builtins/unset_builtins.c \
./srcs/builtins/export_builtins.c \
./srcs/builtins/echo_builtins.c \
./srcs/ft_splitlen.c \
./srcs/vector_int.c \
./srcs/cpy_split.c \
./srcs/manage_space.c \
./srcs/pars.c \
./srcs/here_doc.c \
./srcs/exec.c \
./srcs/exec_cmds.c \
./srcs/exec_utils.c \
./srcs/signal_handler.c \
./srcs/init_minishell.c \
./srcs/update_shell.c \
./srcs/quote_utilities.c \
./srcs/builtins/export_show_builtins.c \
./srcs/generate_tmp_file.c \
./srcs/show_commands.c \
./srcs/manage_env_variable.c \
./srcs/copy_with_space.c \
./srcs/size_space.c \
./srcs/len_utilities.c \
./srcs/check_operator.c \
./srcs/fill_list.c \
./srcs/manage_list.c \
./srcs/parsing.c \
./srcs/is_split.c \
./srcs/is_cmd.c \
./srcs/is_absolute.c \
./srcs/is_builtins.c \
./srcs/clean_minishell.c \
./srcs/clean_list.c \
./srcs/quote_len.c \
./srcs/manage_env.c \
./srcs/copy_new_string.c \
./srcs/copy_errno.c \
./srcs/is_operator.c \
./srcs/create_process.c \
./srcs/set_process.c

all:	${NAME}

OBJ = ${SRCS:.c=.o}

OBJ_D = ${OBJ:.o=.d}

%.o : %.c
		$(CC) $(FLAGS) -c $< -o $@

-include ${OBJ_D}

${NAME} : ${OBJ} ${LIBFT}
		${CC} ${FLAGS} ${OBJ} -lreadline -o ${NAME} ${LIBFT}

${LIBFT} : FORCE
		make -C ./libft

FORCE: 

clean:
		make -C ./libft clean
		rm -f ${OBJ} ${OBJ_D}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: clean fclean re all FORCE
