# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcourtoi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 13:46:50 by jcourtoi          #+#    #+#              #
#    Updated: 2022/05/27 15:36:49 by jcourtoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long

SRCS =	srcs_n/main.c srcs_n/init.c srcs_n/parsing.c srcs_n/put_img.c \
	utils_n/gnl/get_next_line.c utils_n/gnl/get_next_line_utils.c\
	srcs_n/init_struct.c srcs_n/close_map.c srcs_n/action.c srcs_n/mlx.c\
	srcs_n/errors.c srcs_n/moving.c srcs_n/bitshift.c

OBJS =	${SRCS:.c=.o}

CC =	cc

CFLAGS = -g -Wall -Wextra -Werror -I/usr/include -Imlx_linux  

MLXFLAGS = -L -lmlx -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o

RM = rm -rf

all: ${NAME}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}: ${OBJS}
	${MAKE} -C ./libs_n/libft
	${MAKE} -C ./minilibx
	${MAKE} -C ./utils_n/ft_printf
	${CC} ${CFLAGS} ${OBJS} ${MLXFLAGS} -L ./minilibx/*.a \
		./utils_n/ft_printf/*.o ./libs_n/libft/libft.a -o ${NAME}

clean:
	${MAKE} -C ./libs_n/libft fclean
	${MAKE} -C ./minilibx clean
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
