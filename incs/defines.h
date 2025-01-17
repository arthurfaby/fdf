/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:26:16 by afaby             #+#    #+#             */
/*   Updated: 2022/04/29 10:07:11 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define BUFFER_SIZE 100

# define ABS(x) x < 0 ? -x : x
# define MAX(a, b) a < b ? b : a
# define MIN(a, b) a < b ? a : b
# define RGB(r, g, b) ((((r) << 8) + (g)) << 8) + (b)


#endif
