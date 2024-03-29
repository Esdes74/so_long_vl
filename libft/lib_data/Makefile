# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 10:46:11 by eslamber          #+#    #+#              #
#    Updated: 2023/01/05 17:51:26 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Definitions of compilation options
FLAGS := -Wall -Werror -Wextra -fsanitize=address -fno-omit-frame-pointer
CC := gcc

# Definitions of librairies repertories
LIB_LIST := l_list/
LIB_LIST_SRC := $(LIB_LIST)src/
LIB_LIST_OBJ := $(LIB_LIST)obj/

LIB_LIST_IND := l_list_ind/
LIB_LIST_IND_SRC := $(LIB_LIST_IND)src/
LIB_LIST_IND_OBJ := $(LIB_LIST_IND)obj/

LIB_QUEUE := l_queue/
LIB_QUEUE_SRC := $(LIB_QUEUE)src/
LIB_QUEUE_OBJ := $(LIB_QUEUE)obj/

LIB_STACK := l_stack/
LIB_STACK_SRC := $(LIB_STACK)src/
LIB_STACK_OBJ := $(LIB_STACK)obj/

LIB_SIMPLE := l_simple/
LIB_SIMPLE_SRC := $(LIB_SIMPLE)src/
LIB_SIMPLE_OBJ := $(LIB_SIMPLE)obj/

LIB_TREE := l_tree/
LIB_TREE_SRC := $(LIB_TREE)src/
LIB_TREE_OBJ := $(LIB_TREE)obj/

LIB_GNRL := l_gnrl/
LIB_GNRL_SRC := $(LIB_GNRL)src/
LIB_GNRL_OBJ := $(LIB_GNRL)obj/

ALL_LIB_OBJ_DIR := $(LIB_LIST_OBJ) \
				   $(LIB_LIST_IND_OBJ) \
				   $(LIB_QUEUE_OBJ) \
				   $(LIB_STACK_OBJ) \
				   $(LIB_SIMPLE_OBJ) \
				   $(LIB_TREE_OBJ) \
				   $(LIB_GNRL_OBJ)

ALL_LIB_SRC_DIR := $(LIB_LIST_SRC) \
				   $(LIB_LIST_IND_SRC) \
				   $(LIB_QUEUE_SRC) \
				   $(LIB_STACK_SRC) \
				   $(LIB_SIMPLE_SRC) \
				   $(LIB_TREE_SRC) \
				   $(LIB_GNRL_SRC)

# Definition of variables needed for librairie compilation
LIB := lib_data.a

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

QUEUE_LIB := init_queue.c \

QUEUE_LIB_H := $(LIB_QUEUE)lib_queue.h
QUEUE_OBJ_LIB := $(QUEUE_LIB:%.c=$(LIB_QUEUE_OBJ)%.o)

STACK_LIB := init_stack.c \
			 stacking.c \
			 stacking_val.c \
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

GNRL_LIB := init_data.c \
			size.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_printf.c \
			conv_ten_to_hex.c \
			print_list.c
GNRL_LIB_H := lib_data.h
GNRL_OBJ_LIB := $(GNRL_LIB:%.c=$(LIB_GNRL_OBJ)%.o)

ALL_OBJ_LIB := $(LIST_OBJ_LIB) \
			   $(LIST_IND_OBJ_LIB) \
			   $(QUEUE_OBJ_LIB) \
			   $(STACK_OBJ_LIB) \
			   $(SIMPLE_OBJ_LIB) \
			   $(TREE_OBJ_LIB) \
			   $(GNRL_OBJ_LIB)

# Definitions of differents printed colors
LIGHTBLUE := '\e[0;32m'
RED := '\e[0;31m'
NEUTRAL := '\e[0m'

# Compilations rules
all: $(LIB)

$(LIB): $(ALL_OBJ_LIB)
	ar rc $@ $^
	ranlib $@

$(LIST_OBJ_LIB): $(LIB_LIST_OBJ)%.o: $(LIB_LIST_SRC)%.c $(LIST_LIB_H)
	$(CC) $(FLAGS) -c $< -o $@

$(LIST_IND_OBJ_LIB): $(LIB_LIST_IND_OBJ)%.o: $(LIB_LIST_IND_SRC)%.c \
$(LIST_IND_LIB_H) lib_data.h
	$(CC) $(FLAGS) -c $< -o $@

$(QUEUE_OBJ_LIB): $(LIB_QUEUE_OBJ)%.o: $(LIB_QUEUE_SRC)%.c $(QUEUE_LIB_H) \
	lib_data.h
	$(CC) $(FLAGS) -c $< -o $@

$(STACK_OBJ_LIB): $(LIB_STACK_OBJ)%.o: $(LIB_STACK_SRC)%.c $(STACK_LIB_H) \
	lib_data.h
	$(CC) $(FLAGS) -c $< -o $@

$(SIMPLE_OBJ_LIB): $(LIB_SIMPLE_OBJ)%.o: $(LIB_SIMPLE_SRC)%.c $(SIMPLE_LIB_H) \
	lib_data.h
	$(CC) $(FLAGS) -c $< -o $@

$(TREE_OBJ_LIB): $(LIB_TREE_OBJ)%.o: $(LIB_TREE_SRC)%.c $(TREE_LIB_H) lib_data.h
	$(CC) $(FLAGS) -c $< -o $@

$(GNRL_OBJ_LIB): $(LIB_GNRL_OBJ)%.o: $(LIB_GNRL_SRC)%.c $(GNRL_LIB_H) lib_data.h
	$(CC) $(FLAGS) -c $< -o $@

#
### Test rule
#

vartest:
	@echo "ALL_OBJ_LIB = $(ALL_OBJ_LIB)"

#
### Directories rules
#

dir:
	@echo -e $(LIGHTBLUE)make librairies directories$(NEUTRAL)
	mkdir -p $(ALL_LIB_OBJ_DIR)
	@echo -e $(LIGHTBLUE)done$(NEUTRAL)
	@echo

#
### Print rules
#

# Compilation of librairie with print options
print: print_ob $(ALL_OBJ_LIB) print_lb $(LIB) print_le

print_ob:
	@echo -e $(LIGHTBLUE)compilation lib objects files$(NEUTRAL)

print_oe:
	@echo -e $(LIGHTBLUE)compilation lib objetcs files done$(NEUTRAL)
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
	@echo -e $(LIGHTBLUE)remove all $(RED)librairires objects files$(NEUTRAL)
	@rm -rfv $(ALL_OBJ_LIB)
	@echo

cleanlib: 
	@echo -e $(LIGHTBLUE)remove $(RED)lib file$(NEUTRAL)
	@rm -rfv $(LIB)
	@echo

# Directories cleaning rules
cleandir: 
	@echo -e $(LIGHTBLUE)remove all $(RED)librairies directories$(NEUTRAL)
	@rm -rfv $(ALL_LIB_OBJ_DIR)
	@echo

clean_git:
	@echo -e $(LIGHTBLUE)remove all $(RED)gitignore files$(NEUTRAL)
	@rm -rfv ./*/obj/.gitignore
	@echo

gitignor: 
	@echo -e $(LIGHTBLUE)reediting of differents $(RED)gitignores$(NEUTRAL)
	touch ./l_list/obj/.gitignore
	@echo "*" > ./l_list/obj/.gitignore
	@echo !.gitignore >> ./l_list/obj/.gitignore
	cp ./l_list/obj/.gitignore ./l_simple/obj
	cp ./l_list/obj/.gitignore ./l_queue/obj
	cp ./l_list/obj/.gitignore ./l_list_ind/obj
	cp ./l_list/obj/.gitignore ./l_gnrl/obj
	cp ./l_list/obj/.gitignore ./l_stack/obj
	cp ./l_list/obj/.gitignore ./l_tree/obj
	@echo

# Full cleaning rules
fclean: clean cleanlib clean_git cleandir dir gitignor

# Remake rules
re: fclean all

# Remakes rules with print options
reprint: fclean print

.PHONY: print_oe print_ob print_le print_lb reprint print
.PHONY: re all dir gitignore
.PHONY: fclean clean cleanlib cleandir clean_git
