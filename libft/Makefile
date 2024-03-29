# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 15:42:31 by eslamber          #+#    #+#              #
#    Updated: 2023/02/07 12:08:40 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
### Definitions of variables
#

# Definitions of compilation options
VALG := -g
FLAGS := -Wall -Werror -Wextra -g#3 -fsanitize=address -fno-omit-frame-pointer
CC := gcc

# Definition of variable librairie
LIB_FCT := lib_fct/
LIB_DATA := lib_data/

LIB := libft.a
HEADERS := $(LIB_DATA)lib_data.h \
		   $(LIB_FCT)lib_fct.h

# Definitions of librairies repositories
LIB_LIST := $(LIB_DATA)l_list/
LIB_LIST_SRC := $(LIB_LIST)src/
LIB_LIST_OBJ := $(LIB_LIST)obj/

LIB_LIST_IND := $(LIB_DATA)l_list_ind/
LIB_LIST_IND_SRC := $(LIB_LIST_IND)src/
LIB_LIST_IND_OBJ := $(LIB_LIST_IND)obj/

LIB_QUEUE := $(LIB_DATA)l_queue/
LIB_QUEUE_SRC := $(LIB_QUEUE)src/
LIB_QUEUE_OBJ := $(LIB_QUEUE)obj/

LIB_STACK := $(LIB_DATA)l_stack/
LIB_STACK_SRC := $(LIB_STACK)src/
LIB_STACK_OBJ := $(LIB_STACK)obj/

LIB_SIMPLE := $(LIB_DATA)l_simple/
LIB_SIMPLE_SRC := $(LIB_SIMPLE)src/
LIB_SIMPLE_OBJ := $(LIB_SIMPLE)obj/

LIB_TREE := $(LIB_DATA)l_tree/
LIB_TREE_SRC := $(LIB_TREE)src/
LIB_TREE_OBJ := $(LIB_TREE)obj/

LIB_GNRL := $(LIB_DATA)l_gnrl/
LIB_GNRL_SRC := $(LIB_GNRL)src/
LIB_GNRL_OBJ := $(LIB_GNRL)obj/

LIB_MATH := $(LIB_FCT)lib_math/
LIB_MATH_SRC := $(LIB_MATH)src/
LIB_MATH_OBJ := $(LIB_MATH)obj/

LIB_PRINT := $(LIB_FCT)lib_print/
LIB_PRINT_SRC := $(LIB_PRINT)src/
LIB_PRINT_OBJ := $(LIB_PRINT)obj/

LIB_MEM := $(LIB_FCT)lib_mem/
LIB_MEM_SRC := $(LIB_MEM)src/
LIB_MEM_OBJ := $(LIB_MEM)obj/

LIB_STR := $(LIB_FCT)lib_str/
LIB_STR_SRC := $(LIB_STR)src/
LIB_STR_OBJ := $(LIB_STR)obj/

ALL_LIB_OBJ_DIR := $(LIB_LIST_OBJ) \
				   $(LIB_LIST_IND_OBJ) \
				   $(LIB_QUEUE_OBJ) \
				   $(LIB_STACK_OBJ) \
				   $(LIB_SIMPLE_OBJ) \
				   $(LIB_TREE_OBJ) \
				   $(LIB_GNRL_OBJ) \
				   $(LIB_MATH_OBJ) \
				   $(LIB_PRINT_OBJ) \
				   $(LIB_MEM_OBJ) \
				   $(LIB_STR_OBJ)

ALL_LIB_SRC_DIR := $(LIB_LIST_SRC) \
				   $(LIB_LIST_IND_SRC) \
				   $(LIB_QUEUE_SRC) \
				   $(LIB_STACK_SRC) \
				   $(LIB_SIMPLE_SRC) \
				   $(LIB_TREE_SRC) \
				   $(LIB_GNRL_SRC) \
				   $(LIB_MATH_SRC) \
				   $(LIB_PRINT_SRC) \
				   $(LIB_MEM_SRC) \
				   $(LIB_STR_SRC)

# Definition of variables needed to librairie's compilation
GNRL_LIB := init_data.c \
			size.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_printf.c \
			conv_ten_to_hex.c \
			print_list.c
GNRL_LIB_H := $(LIB_DATA)lib_data.h
GNRL_OBJ_LIB := $(GNRL_LIB:%.c=$(LIB_GNRL_OBJ)%.o)

LIST_LIB := init_list.c \
			stacking_list.c \
			addback_list.c \
			unstack_list.c \
			rmstack_list.c \
			rmback_list.c \
			delback_list.c
LIST_LIB_H := $(LIB_LIST)lib_list.h
LIST_OBJ_LIB := $(LIST_LIB:%.c=$(LIB_LIST_OBJ)%.o)

LIST_IND_LIB := init_list_ind.c
LIST_IND_LIB_H := $(LIB_LIST_IND)lib_list_ind.h
LIST_IND_OBJ_LIB := $(LIST_IND_LIB:%.c=$(LIB_LIST_IND_OBJ)%.o)

QUEUE_LIB := init_queue.c
QUEUE_LIB_H := $(LIB_QUEUE)lib_queue.h
QUEUE_OBJ_LIB := $(QUEUE_LIB:%.c=$(LIB_QUEUE_OBJ)%.o)

STACK_LIB := init_stack.c \
			 stacking.c \
			 unstack.c \
			 rmstack.c
STACK_LIB_H := $(LIB_STACK)lib_stack.h
STACK_OBJ_LIB := $(STACK_LIB:%.c=$(LIB_STACK_OBJ)%.o)

SIMPLE_LIB := ft_lstadd_back.c \
			  ft_lstadd_front.c \
			  ft_lstclear.c \
			  ft_lstdelone.c \
			  ft_lstiter.c \
			  ft_lstlast.c \
			  ft_lstmap.c \
			  ft_lstnew.c \
			  ft_lstsize.c
SIMPLE_LIB_H := $(LIB_SIMPLE)lib_simple.h
SIMPLE_OBJ_LIB := $(SIMPLE_LIB:%.c=$(LIB_SIMPLE_OBJ)%.o)

TREE_LIB := init_tree.c
TREE_LIB_H := $(LIB_TREE)lib_tree.h
TREE_OBJ_LIB := $(TREE_LIB:%.c=$(LIB_TREE_OBJ)%.o)

MATH_LIB := ft_power.c \
			ft_max.c
MATH_LIB_H := $(LIB_MATH)lib_math.h
MATH_OBJ_LIB := $(MATH_LIB:%.c=$(LIB_MATH_OBJ)%.o)

MEM_LIB := ft_bzero.c \
		   ft_calloc.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_memcpy.c \
		   ft_memmove.c \
		   ft_memset.c
MEM_LIB_H := $(LIB_MEM)lib_mem.h
MEM_OBJ_LIB := $(MEM_LIB:%.c=$(LIB_MEM_OBJ)%.o)

PRINT_LIB := ft_putchar_fd.c \
			 ft_putendl_fd.c \
			 ft_putnbr_fd.c \
			 ft_putstr_fd.c \
			 ft_printf.c \
			 conv_ten_to_hex.c
PRINT_LIB_H := $(LIB_PRINT)lib_print.h
PRINT_OBJ_LIB := $(PRINT_LIB:%.c=$(LIB_PRINT_OBJ)%.o)

STR_LIB := ft_atoi.c \
		   ft_isalnum.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_split.c \
		   ft_strdup.c \
		   ft_strjoin.c \
		   ft_strlcpy.c \
		   ft_strmapi.c \
		   ft_strnstr.c \
		   ft_strtrim.c \
		   ft_tolower.c \
		   ft_in.c \
		   ft_isalpha.c \
		   ft_isdigit.c \
		   ft_itoa.c \
		   ft_strchr.c \
		   ft_striteri.c \
		   ft_strlcat.c \
		   ft_strlen.c \
		   ft_strncmp.c \
		   ft_strrchr.c \
		   ft_substr.c \
		   ft_toupper.c \
		   get_next_line_utils.c \
		   get_next_line.c
STR_LIB_H := $(LIB_STR)lib_str.h \
			 $(LIB_STR)get_next_line.h
STR_OBJ_LIB := $(STR_LIB:%.c=$(LIB_STR_OBJ)%.o)

ALL_OBJ_LIB := $(LIST_OBJ_LIB) \
			   $(LIST_IND_OBJ_LIB) \
			   $(QUEUE_OBJ_LIB) \
			   $(STACK_OBJ_LIB) \
			   $(SIMPLE_OBJ_LIB) \
			   $(TREE_OBJ_LIB) \
			   $(GNRL_OBJ_LIB) \
			   $(MATH_OBJ_LIB) \
			   $(MEM_OBJ_LIB) \
			   $(PRINT_OBJ_LIB) \
			   $(STR_OBJ_LIB)

# Definitions of differents printed colors
LIGHTBLUE := '\e[0;32m'
RED := '\e[0;31m'
NEUTRAL := '\e[0m'
#
### Compilations rules
#

# only lib
all: $(LIB)

$(LIB): $(ALL_OBJ_LIB) libft.h
	ar rc $@ $(ALL_OBJ_LIB)
	ranlib $@

$(LIST_OBJ_LIB): $(LIB_LIST_OBJ)%.o: $(LIB_LIST_SRC)%.c $(LIST_LIB_H) \
	$(LIB_DATA)lib_data.h libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(LIST_IND_OBJ_LIB): $(LIB_LIST_IND_OBJ)%.o: $(LIB_LIST_IND_SRC)%.c \
	$(LIST_IND_LIB_H) $(LIB_DATA)lib_data.h libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(QUEUE_OBJ_LIB): $(LIB_QUEUE_OBJ)%.o: $(LIB_QUEUE_SRC)%.c $(QUEUE_LIB_H) \
	$(LIB_DATA)lib_data.h libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(STACK_OBJ_LIB): $(LIB_STACK_OBJ)%.o: $(LIB_STACK_SRC)%.c $(STACK_LIB_H) \
	$(LIB_DATA)lib_data.h libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(SIMPLE_OBJ_LIB): $(LIB_SIMPLE_OBJ)%.o: $(LIB_SIMPLE_SRC)%.c $(SIMPLE_LIB_H) \
	$(LIB_DATA)lib_data.h libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(TREE_OBJ_LIB): $(LIB_TREE_OBJ)%.o: $(LIB_TREE_SRC)%.c $(TREE_LIB_H) \
	$(LIB_DATA)lib_data.h libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(GNRL_OBJ_LIB): $(LIB_GNRL_OBJ)%.o: $(LIB_GNRL_SRC)%.c $(GNRL_LIB_H) \
	$(LIB_DATA)lib_data.h libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(MATH_OBJ_LIB): $(LIB_MATH_OBJ)%.o: $(LIB_MATH_SRC)%.c $(MATH_LIB_H) \
	$(LIB_FCT)lib_fct.h libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(MEM_OBJ_LIB): $(LIB_MEM_OBJ)%.o: $(LIB_MEM_SRC)%.c $(MEM_LIB_H) \
	$(LIB_FCT)lib_fct.h libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(PRINT_OBJ_LIB): $(LIB_PRINT_OBJ)%.o: $(LIB_PRINT_SRC)%.c $(PRINT_LIB_H) \
	$(LIB_FCT)lib_fct.h libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(STR_OBJ_LIB): $(LIB_STR_OBJ)%.o: $(LIB_STR_SRC)%.c $(STR_LIB_H) \
	$(LIB_FCT)lib_fct.h libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(GNL_OBJ_LIB): $(LIB_GNL_OBJ)%.o: $(LIB_GNL_SRC)%.c $(GNL_LIB_H) \
	$(LIB_FCT)lib_fct.h libft.h
	$(CC) $(FLAGS) -c $< -o $@

#
### Directories rules
#

dir_lib:
	@echo -e $(LIGHTBLUE)make librairies directories$(NEUTRAL)
	mkdir -p $(ALL_LIB_OBJ_DIR)
	@echo -e $(LIGHTBLUE)done$(NEUTRAL)
	@echo

#
### Test rules
#

vartest:
	echo $(ALL_LIB_OBJ_DIR)

#
### Prints rules
#

# Compilation of librairie with print options
printlib: print_ob $(ALL_OBJ_LIB) print_lb $(LIB) print_le

print_ob:
	@echo -e $(LIGHTBLUE)compilation lib objects files$(NEUTRAL)

print_oe:
	@echo -e $(LIGHTBLUE)compilation lib objetcs files done$(NEUTRAL)
	@echo

print_otb:
	@echo -e $(LIGHTBLUE)compilation test objects files$(NEUTRAL)

print_ote:
	@echo -e $(LIGHTBLUE)compilation test objetcs files done$(NEUTRAL)
	@echo

print_eb: print_ote
	@echo -e $(LIGHTBLUE)compilation executables$(NEUTRAL)

print_ee:
	@echo -e $(LIGHTBLUE)compilation executables done$(NEUTRAL)
	@echo

print_lb: print_oe
	@echo -e $(LIGHTBLUE)compilation librairie$(NEUTRAL)

print_le:
	@echo -e $(LIGHTBLUE)compilation librairie done$(NEUTRAL)
	@echo

#
### Cleanup rules
#

# Classiques cleaning rules
clean:
	@echo -e $(LIGHTBLUE)remove all $(RED)objects files$(NEUTRAL)
	make -C mlx_linux clean
	@rm -rfv $(ALL_OBJ_LIB)
	@echo

cleanlib: 
	@echo -e $(LIGHTBLUE)remove $(RED)lib file$(NEUTRAL)
	@rm -rfv $(LIB)
	@echo

# Directories cleaning rules
cleandir: 
	@echo -e $(LIGHTBLUE)remove all $(RED)directories$(NEUTRAL)
	@rm -rfv $(ALL_LIB_OBJ_DIR)
	@echo

clean_git:
	@echo -e $(LIGHTBLUE)remove all $(RED)gitignore files$(NEUTRAL)
	@rm -rfv ./lib_*/*/obj/.gitignore
	@rm -rfv ../test_lib/*/.gitignore
	@echo

gitignor: 
	@echo -e $(LIGHTBLUE)reediting of differents $(RED)gitignores$(NEUTRAL)
	touch lib_data/l_gnrl/obj/.gitignore
	@echo "*" > lib_data/l_gnrl/obj/.gitignore
	@echo !.gitignore >> lib_data/l_gnrl/obj/.gitignore
	cp lib_data/l_gnrl/obj/.gitignore lib_data/l_list/obj
	cp lib_data/l_gnrl/obj/.gitignore lib_data/l_list_ind/obj
	cp lib_data/l_gnrl/obj/.gitignore lib_data/l_stack/obj
	cp lib_data/l_gnrl/obj/.gitignore lib_data/l_simple/obj
	cp lib_data/l_gnrl/obj/.gitignore lib_data/l_queue/obj
	cp lib_data/l_gnrl/obj/.gitignore lib_data/l_tree/obj
	cp lib_data/l_gnrl/obj/.gitignore lib_fct/lib_math/obj
	cp lib_data/l_gnrl/obj/.gitignore lib_fct/lib_str/obj
	cp lib_data/l_gnrl/obj/.gitignore lib_fct/lib_mem/obj
	cp lib_data/l_gnrl/obj/.gitignore lib_fct/lib_print/obj
	@echo

# Full cleaning rules
fclean: clean cleanlib clean_git cleandir dir_lib gitignor

# Remake rules
re: fcleanlib
	make -C mlx_linux re
	make all

# Remakes rules with print options
reprint: fcleanlib printlib

.PHONY: print_oe print_eb print_ee print_ob print_le print_lb reprint printlib
.PHONY: print_otb print_ote
.PHONY: re dir_lib vartest all gitignor
.PHONY: fclean clean cleandir cleanlib clean_git mlx
