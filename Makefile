# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:40:33 by eslamber          #+#    #+#              #
#    Updated: 2023/02/07 15:44:28 by eslamber         ###   ########.fr        #
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
HEADER_LIB := $(LIB_DIR)libft.h \
				#$(LIB_DIR)lib_data/lib_data.h \
				$(LIB_DIR)lib_data/l_list/lib_list.h \
				$(LIB_DIR)lib_data/l_list_ind/lib_list_ind.h \
				$(LIB_DIR)lib_data/l_queue/lib_queue.h \
				$(LIB_DIR)lib_data/l_simple/lib_simple.h \
				$(LIB_DIR)lib_data/l_stack/lib_stack.h \
				$(LIB_DIR)lib_data/l_tree/lib_tree.h \
				$(LIB_DIR)lib_fct/lib_fct.h \
				$(LIB_DIR)lib_fct/lib_math/lib_math.h \
				$(LIB_DIR)lib_fct/lib_mem/lib_mem.h \
				$(LIB_DIR)lib_fct/lib_print/lib_print.h \
				$(LIB_DIR)lib_fct/lib_str/lib_str.h \
				$(LIB_DIR)lib_fct/lib_str/get_next_line.h
HEADER_MLX := $(LIB_DIR)mlx_linux/mlx.h \
				$(LIB_DIR)mlx_linux/mlx_int.h

DEP_MLX := $(MLX) $(HEADER_MLX)
DEP_LIB := $(LIB) $(HEADER_LIB)

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
