# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:40:33 by eslamber          #+#    #+#              #
#    Updated: 2023/02/03 13:31:04 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
### Definitions of variables
#

# Compilation flags
FLAGS := -Wall -Werror -Wextra
#FLAGS += -g -fsanitize=address -fno-omit-frame-pointer
CC := gcc

FLAG_MLX := -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz \
			libft/mlx_linux/libmlx.a libft/mlx_linux/libmlx_Linux.a

# Definition of names variables
LIB := libft.a
NAME := so_long
HEADER := so_long.h \
		  get_next_line.h

# Definition of files variables
SRC := parsing_map.c \
		print_map.c \
		creat_map.c \
		verif_map.c \
		graphics.c \
		key_event.c \
		main.c
OBJ := $(SRC:%.c=%.o)

#
### Compilation rules
#

all: $(LIB) $(NAME)

$(LIB):
	make -C libft/mlx_linux
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ $(FLAG_MLX) -L. libft/$(LIB)

%.O: %.c $(HEADER)
	$(CC) $(FLAGS) -I/usr/include -Ilibft/mlx_linux -c $< -o $@

#
### Cleanup rules
#

clean:
	@rm -rfv $(OBJ)
	make -C libft clean

fclean:
	@rm -rfv $(OBJ)
	@rm -rfv $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re mlx
