# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 19:25:23 by jsivanes          #+#    #+#              #
#    Updated: 2016/04/18 20:20:10 by jsivanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc -Wall -Wextra -Werror

HEAD = ./inc

SRC = src/main.c src/ft_create_tet.c 	\
	  src/ft_tetris.c src/ft_resolve.c  \
	  src/init_map.c

OBJ = $(SRC:.c=.o)

I_LIBFT = -Ilibft

LIBFT = -Llibft $(I_LIBFT) -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $^ -I$(HEAD) $(LIBFT)

%.o: %.c
	@$(CC) -I$(HEAD) -o $@ -c $< $(I_LIBFT)

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

