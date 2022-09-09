/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:47:21 by afaby             #+#    #+#             */
/*   Updated: 2022/04/25 14:00:21 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "libft.h"
#include "functions.h"
#include "defines.h"

int	count_cols(char *path)
{
	int		fd;
	char	*line;
	int		n_x;
	int		i;

	fd = open_file(path);
	line = get_next_line(fd, BUFFER_SIZE);
	i = 0;
	n_x = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			while (line[i] != ' ' && line[i])
				i++;
			n_x++;
		}
		while (line[i] == ' ' && line[i])
			i++;
	}
	close_file(fd);
	return (n_x);
}

int	count_rows(char *path)
{
	int		fd;
	int		n_y;
	char	*res;

	fd = open_file(path);
	n_y = 0;
	res = get_next_line(fd, BUFFER_SIZE);
	while (res)
	{
		free(res);
		res = NULL;
		res = get_next_line(fd, BUFFER_SIZE);
		n_y++;
	}
	close_file(fd);
	return (n_y);
}
