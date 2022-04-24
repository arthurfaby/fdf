# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 15:12:12 by afaby             #+#    #+#              #
#    Updated: 2022/04/24 17:43:21 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(shell find srcs/*.c)

CC = gcc
INCS = incs/
MLX = minilibx
CFLAGS = -Wall -Wextra -Werror -I$(MLX) -L$(MLX) -lmlx -lXext -lX11 -lm -I$(INCS)
NAME = fdf
LIBFT= -Llibft/ -lft -Ilibft/

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) -g $(SRCS) -o $(NAME) $(CFLAGS) $(LIBFT)

clean:
	rm -f $(NAME)

re: clean all
	make re -C libft/
