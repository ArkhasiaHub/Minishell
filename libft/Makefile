NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror -MMD -MP

HEADERS = ./includes/ft_printf.h \
./includes/is_type.h \
./includes/list.h \
./includes/mem_manip \
./includes/string_manip.h \
./includes/write.h \
./includes/get_next_line.h \
./includes/vector.h \

SRCS = ./is_type/ft_isalnum.c \
./is_type/ft_isalpha.c \
./is_type/ft_isascii.c \
./is_type/ft_isdigit.c \
./is_type/ft_isprint.c \
./string_manip/ft_strlen.c \
./mem_manip/ft_bzero.c \
./mem_manip/ft_memmove.c \
./mem_manip/ft_memcmp.c \
./mem_manip/ft_memcpy.c \
./mem_manip/ft_calloc.c \
./mem_manip/ft_memset.c \
./mem_manip/ft_memchr.c \
./conversion/ft_atoi.c \
./conversion/ft_itoa.c \
./string_manip/ft_strnstr.c \
./string_manip/ft_substr.c \
./string_manip/ft_strlcpy.c \
./string_manip/ft_split.c \
./string_manip/ft_toupper.c \
./string_manip/ft_tolower.c \
./string_manip/ft_strncmp.c \
./string_manip/ft_strlcat.c \
./string_manip/ft_strchr.c \
./string_manip/ft_strjoin.c \
./string_manip/ft_strrchr.c \
./string_manip/ft_strdup.c \
./string_manip/ft_strtrim.c \
./string_manip/ft_strmapi.c \
./string_manip/ft_striteri.c \
./write/ft_putchar_fd.c \
./write/ft_putstr_fd.c \
./write/ft_putendl_fd.c \
./write/ft_putnbr_fd.c \
./list/ft_lstnew.c \
./list/ft_lstadd_front.c \
./list/ft_lstsize.c \
./list/ft_lstlast.c \
./list/ft_lstadd_back.c \
./list/ft_lstdelone.c \
./list/ft_lstclear.c \
./list/ft_lstiter.c \
./list/ft_lstmap.c \
./gnl/get_next_line.c \
./gnl/get_next_line_utils.c \
./printf/ft_printf.c \
./printf/ft_printf_utils.c \
./printf/ft_put.c

all: ${NAME}

OBJ = ${SRCS:.c=.o}

OBJ_D = ${OBJ:.o=.d}

%.o : %.c
	${CC} ${FLAGS} -o $@ -c $<

-include $(OBJ_D)

${NAME} : ${OBJ}
	ar -rc ${NAME} ${OBJ}

clean:
	rm -f ${OBJ} $(OBJ_D)

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean re all
