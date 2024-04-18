/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:57:37 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/17 13:43:12 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_wall(t_elements *elements, t_images *img, int x, int y)
{
	mlx_put_image_to_window(elements->mlx, elements->window,
		img->wall, x, y);
}

void	ft_put_grass(t_elements *elements, t_images *img, int x, int y)
{
	mlx_put_image_to_window(elements->mlx, elements->window,
		img->grass, x, y);
}

void	ft_put_coll(t_elements *elements, t_images *img, int x, int y)
{
	mlx_put_image_to_window(elements->mlx, elements->window,
		img->couple, x, y);
}

void	ft_put_exit(t_elements *elements, t_images *img, int x, int y)
{
	mlx_put_image_to_window(elements->mlx, elements->window,
		img->jailclose, x, y);
}

void	ft_put_enemy(t_elements *elements, t_images *img, int x, int y)
{
	mlx_put_image_to_window(elements->mlx, elements->window,
		img->cop, x, y);
}
