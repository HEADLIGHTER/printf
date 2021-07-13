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

SRCS = ft_printf.c ft_printf_utils.c ft_uitoa.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft
ARFLAGS = rc

.PHONY: all clean fclean re

%.o : %.c $(HEADERS) Makefile
	$(CC) $(CCF) -c $< -o $(<:.c=.o)

$(NAME): $(LIBFT) $(OBJS) $(HEADER) Makefile
	make -C libft
	ar rc libft/libft.a $(OBJS)
	cp libft/libft.a $(NAME)

all: $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
