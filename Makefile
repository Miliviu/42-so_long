# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhagon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 09:38:55 by juhagon           #+#    #+#              #
#    Updated: 2021/12/14 09:38:59 by juhagon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c map.c gnl/get_next_line.c gnl/get_next_line_utils.c moves.c so_long_utils.c error_check.c main.c error_check_aux.c map_utils.c moves_utils.c misc_functions.c
OBJS = ${SRCS:.c=.o}
GCC   = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long
RM = rm -f

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${GCC} $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all:	${NAME}
clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re: fclean all

.PHONY:		all clean fclean re
