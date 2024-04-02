SRCS = ft_push_swap.c ft_check_input.c ft_do_moves.c ft_double_moves.c\
		ft_moves.c ft_utils.c ft_sort.c ft_sort_small.c

OBJS = ${SRCS:.c=.o}

HEADER = ft_push_swap.h
NAME = push_swap
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c	Makefile ${HEADER} 
	${CC} ${CFLAGS} -c $< -o $@ #${<:.c=.o}

all:        ${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:     clean
			${RM} ${NAME}

re:         fclean all

.PHONY: all clean fclean re
