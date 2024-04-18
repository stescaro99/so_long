/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_rev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:04:30 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/18 15:17:19 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_kill(t_elements *elements, t_images *img, int x, int y)
{
	mlx_put_image_to_window(elements->mlx, elements->window,
		img->killing, x, y);
}

void	ft_put_rev_kill(t_elements *elements, t_images *img, int x, int y)
{
	mlx_put_image_to_window(elements->mlx, elements->window,
		img->killingr, x, y);
}

void	ft_put_pinj(t_elements *elements, t_images *img, int x, int y)
{
	mlx_put_image_to_window(elements->mlx, elements->window,
		img->pacciansjail0, x, y);
}

void	ft_put_rev_pinj(t_elements *elements, t_images *img, int x, int y)
{
	mlx_put_image_to_window(elements->mlx, elements->window,
		img->pacciansjail0r, x, y);
}
