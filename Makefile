# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpace <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 21:41:27 by bpace             #+#    #+#              #
#    Updated: 2019/08/17 23:31:03 by hryu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/*.c \

LIB = libft/libft.a

NAME = fillit

all: $(NAME)

$(NAME):
	@make -C libft re
	@gcc -Wall -Werror -Wextra $(SRC) $(LIB) -o $(NAME)

clean:
	@make -C libft clean
	@/bin/rm -f *.o

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all
