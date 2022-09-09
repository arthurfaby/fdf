/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:52:13 by afaby             #+#    #+#             */
/*   Updated: 2022/04/29 10:11:37 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "includes.h"
#include "functions.h"


// rotation around x axis
t_point	*rotateX(t_app *app, t_point *point, double teta)
{
	t_point	*rotated;
	t_point	*temp;

	temp = point;
	rotated = init_point(0, 0, 0, temp->color);
	rotated->x = temp->x + app->x_offset * 2;
	rotated->y = (temp->y + app->y_offset * 2) * cos(teta) - temp->z * sin(teta);
	//rotated->z = ((temp->y + app->y_offset * 2) * sin(teta) + temp->z * cos(teta)) * app->zoom;
	return (rotated);
}

// beta  : rotation around y axis
t_point	*rotateY(t_app *app, t_point *point, double teta)
{
	t_point	*rotated;
	t_point	*temp;

	temp = point;
	rotated = init_point(0, 0, 0, temp->color);
	rotated->x = (temp->x + app->x_offset * 2) * cos(teta) + temp->z * sin(teta);
	rotated->y = temp->y + app->y_offset * 2;
	//rotated->z = (- (temp->x + app->x_offset * 2) * sin(teta) + temp->z * cos(teta)) * app->zoom;
	return (rotated);
}

// teta  : rotation around z axis
t_point	*rotateZ(t_app *app, t_point *point, double teta)
{
	t_point	*rotated;
	t_point	*temp;

	temp = point;
	rotated = init_point(0, 0, 0, temp->color);
	rotated->x = (temp->x + app->x_offset * 2) * cos(teta) - (temp->y + app->y_offset * 2) * sin(teta);
	rotated->y = (temp->x + app->x_offset * 2) * sin(teta) + (temp->y + app->y_offset * 2) * cos(teta);
	//rotated->z = temp->z * app->zoom;
	return (rotated);
}

t_point	***rotate(t_app *app, double alpha, double beta, double teta)
{
	int		x;
	int		y;
	t_point	***temp;

	temp = malloc_board(app->n_x, app->n_y);
	x = 0;
	while (x < app->n_y)
	{
		y = 0;
		while (y < app->n_x)
		{
			temp[x][y] = init_point(
				app->board[x][y]->x,
				app->board[x][y]->y,
				app->board[x][y]->z,
				app->board[x][y]->color
			);
			temp[x][y] = rotateX(app, temp[x][y], alpha);
			temp[x][y] = rotateY(app, temp[x][y], beta);
			temp[x][y] = rotateZ(app, temp[x][y], teta);
			y++;
		}
		temp[x][y] = 0;
		x++;
	}
	temp[x] = 0;
	return (temp);
}

t_point	*isometric_projection(t_point *point)
{
	t_point	*final;

	final = init_point(point->x, point->y, 0, point->color);
	return (final);
}
