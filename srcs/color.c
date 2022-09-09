/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:32:45 by afaby             #+#    #+#             */
/*   Updated: 2022/04/29 10:08:44 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "libft.h"
#include "functions.h"


#include <stdio.h>



int	parse_color(char *str, int z)
{
	int		has_comma;
	int		i;
	int		color;

	i = -1;
	has_comma = 0;
	while (str[++i])
		if (str[i] == ',')
			has_comma = 1;
	if (has_comma)
	{
		i = 0;
		while (str[i] != ',')
			i++;
		i += 3;
		color = ft_atoi(ft_convert_base(str + i, "0123456789abcdef", "0123456789"));
		return (color);
	}
	if (z <= 0)
	{
		z = map(z, -500, 0, 0, 255);
		return (RGB(0, 0, 255 - z));
	}
	if (z > 3000)
		return (RGB(255, 255, 255));
	return (RGB(128, 245, 0));
}
