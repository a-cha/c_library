# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/29 12:48:54 by sadolph           #+#    #+#              #
#    Updated: 2021/01/15 19:53:57 by sadolph          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile
CC := nasm
FLAGS := -f macho64

# Directories
INCS_DIR := ./includes/
OBJ_DIR := ./obj/
SRC_DIR := ./src/
TEST_DIR := ./tests/

# Files
NAME := libasm.a
TEST_FILE := $(TEST_DIR)test.c
SRCS :=					\
ft_read.s				\
ft_strcmp.s				\
ft_strcpy.s				\
ft_strdup.s				\
ft_strlen.s				\
ft_write.s				\
ft_atoi_base.s			\
ft_list_size.s			\
ft_list_push_front.s	\
ft_list_remove_if.s		\
ft_list_sort.s			\

OBJS := ${SRCS:.s=.o}
O_WITH_DIR := $(addprefix $(OBJ_DIR), $(OBJS))

# Colors
BOLD=\033[1m
GREEN=\033[32m
RED=\033[31m
BLUE=\033[36m
STD=\033[0m

# Rules and dependencies
all: $(NAME)

$(NAME): $(O_WITH_DIR)
	ar rc $(NAME) $?
	ranlib $(NAME)
	@echo "$(BOLD)Library file $(BLUE)$(NAME) $(STD)$(BOLD)$(GREEN)created$(STD)"

test: $(NAME)
	gcc -o asm -I $(INCS_DIR) $(TEST_FILE) $(NAME)
	@echo "$(BOLD)Binary file$(BLUE) asm $(STD)$(BOLD)$(GREEN)created$(STD)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.s $(INCS_DIR)libasm.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INCS_DIR) $< -o $@

# Standard rules
clean:
	rm -rf $(OBJ_DIR)
	@echo "$(BOLD)All $(BLUE)object files$(RED) deleted$(STD)"
fclean: clean
	rm -f $(NAME)
	rm -f asm
	@echo "$(BOLD)Library $(BLUE)$(NAME)$(RED) deleted$(STD)"

re: fclean all

.PHONY: all clean fclean re exec
