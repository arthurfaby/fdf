/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:49:09 by afaby             #+#    #+#             */
/*   Updated: 2022/04/29 11:29:30 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	img_pixel_put(t_app *app, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (y >= app->height || y < 0)
		return ;
	if (x >= app->width || x < 0)
		return ;
	i = app->img->bpp - 8;
	pixel = app->img->addr + (y * app->img->line_len) + x * (app->img->bpp / 8);
	while (i >= 0)
	{
		if (app->img->endian)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (app->img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}	
}
