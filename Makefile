# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 15:37:03 by bbellatr          #+#    #+#              #
#    Updated: 2021/07/12 15:59:35 by bbellatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CC_F = -Wall -Werror -Wextra
HEADERS = ft_printf.h

SRCS =

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

%.o : %.c $(HEADERS)
	$(CC) $(CCF) -c $< -o $@
$(NAME):$(OBJS)
	ar -rcs $(NAME) $?

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
