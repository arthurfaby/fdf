/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:21:32 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/25 15:14:32 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int decimal, char *base_to)
{
	if (decimal < 0)
	{
		if (decimal > -(int)ft_strlen(base_to))
			return (1);
	}
	else
		if (decimal < (int)ft_strlen(base_to))
			return (1);
	return (1 + ft_nbrlen(decimal / ft_strlen(base_to), base_to));
}

int	ft_get_pos_in_base(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}
