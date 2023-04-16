# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 10:07:27 by maruzibo          #+#    #+#              #
#    Updated: 2023/04/16 18:59:03 by maruzibo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#program name
NAME = push_swap

SRC = main.c uinsert.c getints.c moves.c mess.c  sorting_short_str.c \
	initial_push_tob.c push_to_a.c radix_sort.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft
		@cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
		@rm -f $(OBJ)
		@make clean -C libft

fclean: clean
				@make fclean -C libft
				@rm -f $(NAME)
re: fclean all

.PHONY:			all clean fclean re