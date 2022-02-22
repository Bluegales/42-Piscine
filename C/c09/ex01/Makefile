# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 02:09:09 by pfuchs            #+#    #+#              #
#    Updated: 2022/02/22 02:14:06 by pfuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I ./includes
INCS	= includes
NAME	= libft.a
SRC		= ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
obj		= $(SRC:.c=.o)
dep		= $(obj:.o=.d)

$(NAME): $(obj)
	$(AR) rcs $@ $^

%.d: %.c
	$(CPP) $(CFLAGS) $< >$@

.PHONY: clean
clean:
	rm -f $(obj)

.PHONY: fclean
fclean:	clean
	rm -f $(NAME)

.PHONY: re
re:		fclean all

.PHONY: all
all:	$(NAME)
