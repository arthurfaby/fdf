/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:34:52 by afaby             #+#    #+#             */
/*   Updated: 2022/04/28 17:09:23 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structures.h"

int		open_file(char *path);
int		close_file(int fd);
t_app	*init_app(int width, int height, char *name, char *path);
t_point	***init_board(t_app *app, char *path);
int		count_cols(char *path);
int		count_rows(char *path);
double	map(double b, double start1, double stop1, double start2, double stop2);
int		parse_color(char *str, int z);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
t_point	*isometric_projection(t_point *point);
t_point	*init_point(int x, int y, int z, int color);
t_point	*rotateZ(t_app *app, t_point *point, double teta);
t_point	*rotateY(t_app *app, t_point *point, double teta);
t_point	*rotateX(t_app *app, t_point *point, double teta);
t_point	***rotate(t_app *app, double alpha, double beta, double teta);
t_point	***malloc_board(int n_x, int n_y);
void	print_board(t_app *app);

void	img_pixel_put(t_app *app, int x, int y, int color);
int		render(t_app *app);
void	render_background(t_app *app, int color);
void	render_board(t_app *app);
int		render(t_app *app);

#endif
