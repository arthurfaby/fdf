/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:23:44 by afaby             #+#    #+#             */
/*   Updated: 2022/04/28 14:32:06 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_app
{
	void	*mlx;
	void	*win;
	t_image	*img;
	t_point	***board;
	double	width;
	double	height;
	double	n_x;
	double	n_y;
	double	zoom;
	double	x_offset;
	double	y_offset;
	double	gapx;
	double	gapy;
	double	ssizex;
	double	ssizey;
	double	rx;
	double	ry;
	double	rz;
}	t_app;

#endif
