# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 15:04:16 by amerrouc          #+#    #+#              #
#    Updated: 2019/01/15 13:05:52 by amerrouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = amerrouc.filler

SRC = src/test.c src/init.c src/piece_info.c src/format.c src/error.c	\
	  src/put_piece.c src/algo.c 

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror -g

INC = -Iincludes/ -ILibft/includes

LIB = Libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	gcc $(FLAG) $(INC) -o $@ -c $<

$(LIB):
	make -C ./libft/

clean:
#	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
#	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
