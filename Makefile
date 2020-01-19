# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarzouk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 17:21:37 by mmarzouk          #+#    #+#              #
#    Updated: 2020/01/14 17:45:26 by mmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G = gcc -Wall -Wextra -Werror
SRC = *.c
NAME = libftprintf.a

all:
			$(G) -c $(SRC)
			ar rc $(NAME) *.o
			ranlib $(NAME)

clean:
			rm -f *.o

fclean: clean
			rm -f $(NAME)

re: fclean all
