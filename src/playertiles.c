/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playertiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:57:22 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/19 11:22:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_rev_player(t_elements *el, t_images *img, int x, int y)
{
	mlx_put_image_to_window(el->mlx, el->window, img->paccians0r, x, y);
}

void	ft_put_player(t_elements *elements, t_images *img, int x, int y)
{
	mlx_put_image_to_window(elements->mlx, elements->window,
		img->paccians0, x, y);
}
