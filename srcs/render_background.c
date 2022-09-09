/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:29:58 by afaby             #+#    #+#             */
/*   Updated: 2022/04/28 17:09:43 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "functions.h"

void	render_background(t_app *app, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < app->width)
	{
		y = 0;
		while (y < app->height)
		{
			img_pixel_put(app, x, y, color);
			y++;
		}
		x++;
	}
}
