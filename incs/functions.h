/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:34:52 by afaby             #+#    #+#             */
/*   Updated: 2022/04/24 17:02:02 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structures.h"

int		open_file(char *path);
int		close_file(int fd);
t_app	*init_app(int width, int height, char *name);
t_point	***init_board(char *path);
int		count_cols(char *path);
int		count_rows(char *path);

#endif
