/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:57:47 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/18 10:05:06 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_elem(t_elements *elem)
{
	if (elem->img)
	{
		ft_free_img(elem, &(elem->img));
		free(elem->img);
	}
	if (elem->window)
		mlx_destroy_window(elem->mlx, elem->window);
	if (elem->mlx)
	{
		mlx_destroy_display(elem->mlx);
		free(elem->mlx);
	}
	if (elem->map)
		ft_freesplit(elem->map);
	return (1);
}

int	ft_freesplit(char **split)
{
	int	i;

	if (split == NULL)
		return (1);
	i = 0;
	while (split[i])
	{
		if (split[i] != NULL)
		{
			free(split[i]);
			split[i] = NULL;
		}
		i++;
	}
	free(split);
	return (1);
}

char	**ft_matrixcpy(char **matrix, int y)
{
	char	**cpy;
	int		i;

	cpy = ft_calloc((y + 1), sizeof(char *));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < y)
	{
		cpy[i] = ft_strdup(matrix[i]);
		i++;
	}
	return (cpy);
}

int	*set_elem(char **map, int height, int base)
{
	int	i;
	int	j;
	int	*elem;

	elem = ft_calloc(3, sizeof(int));
	if (!elem)
		return (NULL);
	i = 0;
	while (++i < height - 1)
	{
		j = 0;
		while (++j < base - 1)
		{
			if (map[i][j] == 'V')
				elem[0]++;
			else if (map[i][j] == 'P')
			{
				elem[1] = j;
				elem[2] = i;
			}
		}
	}
	return (elem);
}

t_elements	set_elements(int base, int height, int collectibles, char **map)
{
	int			*elem;
	t_elements	elements;

	elem = set_elem(map, height, base);
	if (!elem)
		perror("Error!\nElements allocation failed");
	if (!elem)
		exit(ft_freesplit(map));
	elements.villain = elem[0];
	elements.pos_x = elem[1];
	elements.pos_y = elem[2];
	elements.n_moves = (free(elem), 0);
	elements.base = base;
	elements.height = height;
	elements.collectibles = collectibles;
	elements.map = ft_matrixcpy(map, height);
	if (!elements.map)
		perror("Error!\nElements allocation failed");
	if (!elements.map)
		exit(ft_freesplit(map));
	elements.key = 0;
	elements.mlx = NULL;
	elements.window = NULL;
	elements.img = NULL;
	return (elements);
}
