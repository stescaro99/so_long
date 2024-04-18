/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:56:58 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/22 09:11:03 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_cancel(t_elements *elements)
{
	char	*s;
	char	*n;

	n = ft_itoa((elements->n_moves) - 1);
	if (!n)
	{
		perror("Error!\nAllocation failed");
		ft_closegame(elements);
	}
	s = ft_strjoin("Moves : ", n);
	if (!s)
	{
		perror("Error!\nAllocation failed");
		free(n);
		ft_closegame(elements);
	}
	free(n);
	mlx_string_put(elements->mlx, elements->window, 32, 25, 0xCCC4CA, s);
	free(s);
}

void	ft_put_n_moves(t_elements *elements)
{
	char	*s;
	char	*n;

	if (elements->n_moves != 0)
		ft_cancel(elements);
	n = ft_itoa(elements->n_moves);
	if (!n)
	{
		perror("Error!\nAllocation failed");
		ft_closegame(elements);
	}
	s = ft_strjoin("Moves : ", n);
	if (!s)
	{
		perror("Error!\nAllocation failed");
		free(n);
		ft_closegame(elements);
	}
	free(n);
	mlx_string_put(elements->mlx, elements->window, 32, 25, 0x000000, s);
	free(s);
}

void	ft_invalid_movement(t_elements *el)
{
	mlx_string_put(el->mlx, el->window, (el->base - 2) * 64,
		25, 0xFF0000, "Invalid Move!!!");
	mlx_do_sync(el->mlx);
	mlx_string_put(el->mlx, el->window, (el->base - 2) * 64,
		25, 0xCCC4CA, "Invalid Move!!!");
	usleep(500000);
}

void	ft_put_background(t_elements *elements, t_images *img)
{
	int	i;

	i = 0;
	while (i / 2 < elements->base)
	{
		mlx_put_image_to_window(elements->mlx, elements->window,
			img->moves_background, (i * 32), 0);
		i++;
	}
	ft_put_n_moves(elements);
}

char	**set_map(char *mapname)
{
	int		fd;
	char	**map;
	char	*buffer;

	fd = open(mapname, O_RDONLY);
	if (fd < 1)
	{
		perror("Error!\nInvalid map name");
		exit(1);
	}
	buffer = ft_calloc(5001, 1);
	if (!buffer)
	{
		perror("Error!\nBuffer allocation failed");
		exit(1);
	}
	read(fd, buffer, 5000);
	map = ft_split(buffer, '\n');
	if (!map)
	{
		perror("Error!\nMap allocation failed");
		exit(1);
	}
	close(fd);
	return (free(buffer), map);
}
