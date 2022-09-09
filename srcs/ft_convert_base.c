/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:20:42 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/25 15:13:18 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_pos_in_base(char c, char *base);
int	ft_nbrlen(int nbr, char *base);

int	ft_convert(int *res, char c, char *base)
{
	int	pos_in_base;

	pos_in_base = ft_get_pos_in_base(c, base);
	if (pos_in_base == -1)
		return (0);
	*res *= ft_strlen(base);
	*res += pos_in_base;
	return (1);
}

int	ft_isvalid(char *str)
{
	char	*current;
	int		index;
	int		index2;

	current = str;
	index = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (*current)
	{
		if (*current == '+' || *current == '-' || (*current == ' '
				|| (*current >= '\t' && *current <= '\r')))
			return (0);
		current++;
	}
	while (index < current - str)
	{
		index2 = index + 1;
		while (index2 < current - str)
			if (str[index] == str[index2++])
				return (0);
		index++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		minus;
	int		decimal;
	int		size;

	minus = 1;
	if (ft_isvalid(base_from) == 0 || ft_isvalid(base_to) == 0)
		return ((char *)malloc(sizeof(char)));
	decimal = ft_atoi_base(nbr, base_from);
	if (decimal < 0)
		minus = -1;
	size = ft_nbrlen(decimal, base_to);
	if (decimal < 0)
		size++;
	res = malloc((size + 1) * sizeof(char));
	res[size] = '\0';
	while (size--)
	{
		res[size] = base_to[(decimal % ft_strlen(base_to)) * minus];
		decimal = decimal / ft_strlen(base_to);
	}
	if (minus == -1)
		res[0] = '-';
	return (res);
}
