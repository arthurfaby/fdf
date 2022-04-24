/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:31:22 by afaby             #+#    #+#             */
/*   Updated: 2022/04/24 15:34:34 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	return (fd);
}

int	close_file(int fd)
{
	int	ret;

	ret = close(fd);
	if (ret == -1)
		return (0);
	return (1);
}
