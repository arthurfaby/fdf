/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:11:53 by afaby             #+#    #+#             */
/*   Updated: 2022/04/29 10:24:39 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "mlx.h"
#include "includes.h"
#include "functions.h"
#include "defines.h"

t_app	*init_app(int width, int height, char *name, char *path)
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
	app->img = malloc(sizeof(t_img));
	app->width = width;
	app->height = height;
	app->n_x = count_cols(path);
	app->n_y = count_rows(path);
	app->zoom = 2;
	app->gapx = (app->width / 2) / app->n_x * app->zoom;
	app->gapy = app->gapx;
	app->ssizex = app->gapx * app->n_x;
	app->ssizey = app->gapy * app->n_y;
	app->x_offset = (app->width - app->ssizex) / 2;
	app->y_offset = (app->height - app->ssizey) / 2;
	app->rx = 0;
	app->ry = 0;
	app->rz = 0;
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

void	fill_board(t_app *app, t_point ***board, char *path)
{
	int		fd;
	char	**to_treat;
	char	*line;
	int		x;
	int		y;
	int		i;

	x = 0;
	fd = open_file(path);
	line = get_next_line(fd, BUFFER_SIZE);
	while (line)
	{
		to_treat = ft_split(line, ' ');
		i = 0;
		y = 0;
		while (to_treat[i])
		{
			board[x][y] = init_point(
					(y * app->gapy) + app->x_offset,
					(x * app->gapx) + app->y_offset,
					ft_atoi(to_treat[i]), parse_color(to_treat[i], ft_atoi(to_treat[i]))
			);
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

t_point	***init_board(t_app *app, char *path)
{
	int		fd;
	t_point	***board;

	// CHECK ERROR COLS VS ROWS

	board = malloc_board(app->n_x, app->n_y);
	if (!board)
		return (NULL);
	fill_board(app, board, path);
	fd = open_file(path);
	
	close_file(fd);
	return (board);
}
