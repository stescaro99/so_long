/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:21:51 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/16 14:17:55 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **map, int *h, int *b, int *collectibles)
{
	int	elements[2];

	elements[0] = 0;
	elements[1] = 0;
	while (map[++(*h)])
	{
		*b = -1;
		while (map[*h][++(*b)])
		{
			if ((!(*h) || !map[(*h) + 1] || !(*b)
					|| !map[*h][(*b) + 1]) && map[*h][*b] != '1')
				return (0);
			if (map[*h][*b] == 'P')
				elements[0]++;
			else if (map[*h][*b] == 'E')
				elements[1]++;
			else if (map[*h][*b] == 'C')
				(*collectibles)++;
			else if (map[*h][*b] != '0' &&
						map[*h][*b] != '1' && map[*h][*b] != 'V')
				return (0);
		}
	}
	return (elements[0] == 1 && elements[1] == 1 && *collectibles > 0);
}

int	check_dimensions(char **map, int height, int base)
{
	int		i;
	long	b;

	i = 0;
	while (i < height)
	{
		b = ft_strlen(map[i]);
		if (b != base)
			return (0);
		i++;
	}
	return (1);
}

static	int	fill_cell(char **map, int x, int y)
{
	int	result;

	result = 0;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'e';
		return (1 + fill_cell(map, x, y));
	}
	if (map[y][x] != '1' && map[y][x] != 'T' && map[y][x] != 'V')
	{
		map[y][x] = 'T';
		result += fill_cell(map, x, y - 1);
		result += fill_cell(map, x, y + 1);
		result += fill_cell(map, x - 1, y);
		result += fill_cell(map, x + 1, y);
	}
	return (result);
}

int	check_winnable_map(char **map, t_elements elements)
{
	int	result;
	int	i;
	int	j;

	result = fill_cell(map, elements.pos_x, elements.pos_y);
	if (result == 0)
		return (!(ft_freesplit(map)));
	i = 0;
	while (i < elements.height)
	{
		j = 0;
		while (j < elements.base)
		{
			if (map[i][j] == 'C')
				return (!(ft_freesplit(map)));
			j++;
		}
		i++;
	}
	return (ft_freesplit(map));
}
