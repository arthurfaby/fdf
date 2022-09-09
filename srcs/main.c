/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:24:55 by afaby             #+#    #+#             */
/*   Updated: 2022/04/29 10:24:09 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "includes.h"
#include "functions.h"
#include "defines.h"

#include <stdio.h>
# define PI 3.14159

int		palette[1000];

int	hsvtorgb(int h, int s, int v)
{
	int	region;
	int	remainder;
	int	p;
	int	q;
	int	t;

	if (s == 0)
		return (RGB(v, v, v));
	region = h / 43;
	remainder = (h - (region * 43)) * 6;
	p = (v * (255 - s)) >> 8;
	q = (v * (255 - ((s * remainder) >> 8))) >> 8;
	t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;
	if (region == 0)
		return (RGB(v, t, p));
	if (region == 1)
		return (RGB(q, v, p));
	if (region == 2)
		return (RGB(p, v, t));
	if (region == 3)
		return (RGB(p, q, v));
	if (region == 4)
		return (RGB(t, p, v));
	else
		return (RGB(v, p, q));
}


void	init_palette(void)
{
	int	i;

	i = 170;
	while (i < 300)
	{
		palette[i - 170] = hsvtorgb(i, 100, 100);
		i++;
	}
}
void	line(t_app *app, t_point *p1, t_point *p2, int color)
{
	double	dx;
	double	dy;
	int		pixels;
	double	x;
	double	y;

	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	pixels = sqrt((dx * dx) + (dy * dy));
	dx /= pixels;
	dy /= pixels;
	x = p1->x;
	y = p1->y;
	while (pixels)
	{
		img_pixel_put(app, x, y, color);
		x += dx;
		y += dy;
		--pixels;
	}
}

double	map(double n, double start1, double stop1, double start2, double stop2)
{
	double	start_prop;
	double	res;

	start_prop = n / (start1 + stop1);
	res = (start_prop * (stop2 - start2) + start2);
	return (res);
}

void	print_board(t_app *app)
{
	int		x;
	int		y;
	t_point	***rotated;

	printf("rx : %f, ry : %f, rz : %f\n", app->rx, app->ry, app->rz);
	rotated = rotate(app, app->rx, app->ry, app->rz);
	x = 0;
	while (rotated[x])
	{
		y = 0;
		while (rotated[x][y])
		{
			if (x < app->n_y - 1)
				line(app, rotated[x][y], rotated[x + 1][y], rotated[x][y]->color);
			if (y < app->n_x - 1)
				line(app, rotated[x][y], rotated[x][y + 1], rotated[x][y]->color);
			img_pixel_put(app, rotated[x][y]->x, rotated[x][y]->y, rotated[x][y]->color);
			y++;
		}
		x++;
	}
	x = 0;
	while (rotated[x])
	{
		y = 0;
		while (rotated[x][y])
		{
			free(rotated[x][y]);
			y++;
		}
		free(rotated[x]);
		x++;
	}
	free(rotated);
}

void	refresh(t_app *app)
{
	int	x;
	int	y;

	app->gapx = (app->width / 2) / app->n_x * app->zoom;
	app->gapy = app->gapx;
	app->ssizex = app->gapx * app->n_x;
	app->ssizey = app->gapy * app->n_y; 
	x = 0;
	while (app->board[x])
	{
		y = 0;
		while (app->board[x][y])
		{
			app->board[x][y]->x = (y * app->gapy) + (app->width - app->ssizex) / 2 + app->x_offset;
			app->board[x][y]->y = (x * app->gapy) + (app->height - app->ssizey) / 2 + app->y_offset;
			y++;
		}
		x++;
	}
}

int	mouse_hook(int button, int x, int y, t_app *app)
{
	int	r;

	r = 0;
	(void)x;
	(void)y;
	if (button == 4 && app->zoom < 5)
	{
		app->zoom += 0.09;
		r = 1;
	}
	if (button == 5 && app->zoom > 0.2)
	{
		app->zoom -= 0.09;
		r = 1;
	}
	if (r)
	{
		refresh(app);
	}
	return (0);
}

int	key_hook(int keycode, t_app *app)
{
	if (keycode == 'a')
		app->x_offset += 20;
	if (keycode == 'w')
		app->y_offset += 20;
	if (keycode == 'd')
		app->x_offset -= 20;
	if (keycode == 's')
		app->y_offset -= 20;
	if (keycode == 't')
		app->rx += PI / 16;
	if (keycode == 'y')
		app->rx -= PI / 16;
	if (keycode == 'g')
		app->ry += PI / 16;
	if (keycode == 'h')
		app->ry -= PI / 16;
	if (keycode == 'b')
		app->rz += PI / 16;
	if (keycode == 'n')
		app->rz -= PI / 16;
	refresh(app);
	return (0);
}


int	main(int argc, char **argv)
{
	t_app	*app;
	
	// -------------------
	// -------------------

	init_palette();
	if (argc != 2)
		return (0);
	app = init_app(900, 900, "My fdf !", argv[1]);
	if (!app)
		return (0);
	app->img->img = mlx_new_image(app->mlx, app->width, app->height); 
	app->img->addr = mlx_get_data_addr(app->img->img, &app->img->bpp, &app->img->line_len, &app->img->endian);
	app->board = init_board(app, argv[1]);
	//display(app);
	mlx_loop_hook(app->mlx, &render, app);
	mlx_key_hook(app->win, key_hook, app);
  	mlx_mouse_hook(app->win, mouse_hook, app);
	mlx_loop(app->mlx);
}
