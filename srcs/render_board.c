/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:57:28 by afaby             #+#    #+#             */
/*   Updated: 2022/04/28 17:09:51 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "functions.h"

void	render_board(t_app *app)
{
	int	x;
	int	y;

	x = 0;
	while (x < app->width)
	{
		y = 0;
		while (y < app->height)
		{
			img_pixel_put(
				app,
				x,
				y,
				app->board[x][y]->color
				);
			y++;
		}
		x++;
	}
}
