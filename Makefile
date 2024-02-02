# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 15:48:57 by ctruchot          #+#    #+#              #
#    Updated: 2024/02/02 19:33:19 by ctruchot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_LIST = push_swap_list

SRC = main.c \
		parsing_arguments.c \
		utils.c \
		ft_atoi.c \
		ft_split.c \
		instructions1.c

SRC_LIST = main_list.c \
		parsing_arguments_list.c \
		ft_atoi_list.c \
		ft_split_list.c \
		utils_list.c \
		# instructions1.c

OBJ = $(SRC:%.c=%.o)
OBJ_LIST = $(SRC_LIST:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)
list: $(NAME_LIST)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_LIST): $(OBJ_LIST)
	$(CC) $(CFLAGS) $(OBJ_LIST) -o $(NAME_LIST)

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_LIST)


fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_LIST)


re: fclean
	$(MAKE) $(NAME)

.PHONY: clean all fclean re all
	