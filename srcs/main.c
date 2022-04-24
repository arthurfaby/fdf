/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:24:55 by afaby             #+#    #+#             */
/*   Updated: 2022/04/24 17:59:20 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "includes.h"
#include "functions.h"


#include <stdio.h>

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
	(void)board;
	printf("Board init !\n");
	mlx_loop(app->mlx);
}
