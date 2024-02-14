# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 15:48:57 by ctruchot          #+#    #+#              #
#    Updated: 2024/02/14 18:01:48 by ctruchot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c \
		parsing_arguments.c \
		error_checker.c \
		utils.c \
		utils_lists.c \
		ft_printf.c \
		ft_print_nbr.c \
		instructions1.c \
		instructions2.c \
		instructions3.c \
		ft_split.c \
		order_list.c \
		order_list2.c \
		fill_updates_stacks.c \
		get_info.c \
		get_info2.c

OBJ = $(SRC:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(DEP)

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) $(NAME)

.PHONY: clean all fclean re all
	