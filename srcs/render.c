/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:06:25 by afaby             #+#    #+#             */
/*   Updated: 2022/04/28 15:14:30 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "structures.h"
#include "functions.h"

int	render(t_app *app)
{
	if (app->win == NULL)
		return (1);
	render_background(app, 0);
	print_board(app);
	//render_board(app);
	mlx_put_image_to_window(app->mlx, app->win, app->img->img, 0, 0);
	return (0);
}
