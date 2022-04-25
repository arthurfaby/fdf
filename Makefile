# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 15:12:12 by afaby             #+#    #+#              #
#    Updated: 2022/04/25 09:57:52 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(shell find srcs/*.c)

CC = gcc
INCS = incs/
MLX = libs/minilibx
CFLAGS = -Wall -Wextra -Werror -I$(MLX) -L$(MLX) -lmlx -lXext -lX11 -lm -I$(INCS)
NAME = fdf
LIBFT_DIR = libs/libft
LIBFT= -L$(LIBFT_DIR) -lft -I$(LIBFT_DIR)

all: $(NAME)

$(NAME):
	make -C $(LIBFT_DIR)
	$(CC) -g $(SRCS) -o $(NAME) $(CFLAGS) $(LIBFT)

clean:
	rm -f $(NAME)

re: clean all
	make re -C $(LIBFT_DIR)
