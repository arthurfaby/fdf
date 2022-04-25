/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:24:55 by afaby             #+#    #+#             */
/*   Updated: 2022/04/25 10:58:15 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "includes.h"
#include "functions.h"


#include <stdio.h>

void	print_board(t_app *app, t_point ***board)
{
	int	x;
	int	y;

	x = 0;
	(void)app;
	while (board[x])
	{
		y = 0;
		while (board[x][y])
		{
			//mlx_pixel_put(app->mlx, app->win, board[x][y]->x * 3, board[x][y]->y * 3, board[x][y]->color);
			printf("\033[0;33mx : %d, y : %d, z : %d\n", board[x][y]->x, board[x][y]->y, board[x][y]->z);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_app	*app;
	t_point	***board;

	if (argc != 2)
		return (0);
	app = init_app(500, 500, argv[0]);
	if (!app)
		return (0);
	board = init_board(argv[1]);
	print_board(app, board);
	printf("n_x : %d, n_y : %d\n", count_cols(argv[1]) ,count_rows(argv[1]));
	mlx_loop(app->mlx);
}
