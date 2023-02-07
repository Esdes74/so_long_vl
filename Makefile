# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:40:33 by eslamber          #+#    #+#              #
#    Updated: 2023/02/07 16:19:42 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
### Definitions of variables
#

# Compilation flags
FLAGS := -Wall -Werror -Wextra #-O3
#FLAGS += -g -fsanitize=address -fno-omit-frame-pointer
CC := gcc

FLAG_MLX := libft/mlx_linux/libmlx.a -lm -L/usr/lib -lXext -lX11 -lz
#			-Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz \
			libft/mlx_linux/libmlx.a libft/mlx_linux/libmlx_Linux.a

#
### Definition of names variables
#

# Definition of LIB variables
LIB_DIR := libft/
LIB := $(LIB_DIR)libft.a
MLX := $(LIB_DIR)mlx_linux/libmlx.a \
		$(LIB_DIR)mlx_linux/libmlx_Linux.a

# Definition of project variables
NAME := so_long
HEADER := so_long.h

# Definition of files variables
SRC := parsing_map.c \
	   creat_map.c \
	   verif_map.c \
	   graphics.c \
	   key_event.c \
	   main.c
OBJ := $(SRC:%.c=%.o)

#
### Compilation rules
#

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ $(FLAG_MLX) -L. $(LIB)

%.o: %.c $(HEADER) $(LIB) $(MLX)
	$(CC) $(FLAGS) -I/usr/include -Ilibft/mlx_linux -Ilibft -c $< -o $@

$(LIB): FORCE
	make -C $(LIB_DIR)

$(MLX): FORCE
	make -C $(LIB_DIR)mlx_linux

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

.PHONY: all clean fclean re mlx FORCE
