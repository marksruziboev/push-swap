# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 18:27:42 by maruzibo          #+#    #+#              #
#    Updated: 2023/04/17 16:49:18 by maruzibo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
      ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c\
      ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c\
      ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c\
      ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c \
      ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c\
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BSRC =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)
	
RM = rm -f

AR = ar -rcs

.PHONY:    all, clean, fclean, re

all:    $(NAME)

$(NAME):    $(OBJ)
	@$(AR) $(NAME) $(OBJ)

bonus:	$(OBJ) $(BOBJ)
	@$(AR) $(NAME) $(OBJ) $(BOBJ)


clean:
	$(RM) $(OBJ) $(BOBJ)

fclean:    clean
	$(RM) $(NAME)
	
re: fclean all
