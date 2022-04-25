/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:11:53 by afaby             #+#    #+#             */
/*   Updated: 2022/04/25 11:13:18 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "mlx.h"
#include "includes.h"
#include "functions.h"
#include "defines.h"

t_app	*init_app(int width, int height, char *name)
{
	t_app	*app;

	app = malloc(sizeof(t_app));
	if (!app)
		return (0);
	app->mlx = mlx_init();
	if (!app->mlx)
		return (0);
	app->win = mlx_new_window(app->mlx, width, height, name);
	if (!app->win)
		return (0);
	app->width = width;
	app->height = height;
	return (app);
}

t_point	*init_point(int x, int y, int z, int color)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	if (!new)
		return (0);
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = color;
	return (new);
}

void	fill_board(t_point ***board, char *path)
{
	int		fd;
	char	**to_treat;
	char	*line;
	int		x;
	int		y;
	int		i;

	x = 0;
	i = 0;
	fd = open_file(path);
	line = get_next_line(fd, BUFFER_SIZE);
	while (line)
	{
		to_treat = ft_split(line, ' ');
		y = 0;
		while (to_treat[i])
		{
			board[y][x] = init_point(x, y, ft_atoi(to_treat[i]), 0xffffff);
			i++;
			y++;
		}
		board[x][y] = 0;
		free(line);
		ft_free_double_pointer((void **)to_treat);
		line = get_next_line(fd, BUFFER_SIZE);
		x++;
	}
	board[x] = 0;
}

t_point	***malloc_board(int n_x, int n_y)
{
	t_point	***board;
	int		i;
	
	i = 0;
	board = malloc((n_y + 1) * sizeof(t_point**));
	if (!board)
		return (0);
	while (i < n_y)
	{
		board[i] = malloc((n_x  + 1) * sizeof(t_point*));
		if (!board[i])
		{
			i = 0;
			while (board[i])
			{
				free(board[i]);
				i++;
			}
			free(board);
			return (0);
		}
		i++;
	}
	return (board);
}

t_point	***init_board(char *path)
{
	int		fd;
	t_point	***board;
	int		n_x;
	int		n_y;

	n_x = count_cols(path);
	n_y = count_rows(path);
	// CHECK ERROR COLS VS ROWS

	board = malloc_board(n_x, n_y);
	if (!board)
		return (NULL);
	fill_board(board, path);
	fd = open_file(path);
	
	close_file(fd);
	return (board);
}
