/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_walk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:26:23 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/22 12:08:35 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_walk_right_kjail(t_elements *el, t_images *img, int y, char p)
{
	if (p == 'Q')
	{
		mlx_put_image_to_window(el->mlx, el->window, img->pacciansjail0,
			el->pos_x * 64, y);
		mlx_do_sync(el->mlx);
		usleep(100000);
	}
	mlx_put_image_to_window(el->mlx, el->window, img->pacciansjail1,
		el->pos_x * 64, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	ft_put_exit(el, img, el->pos_x * 64, y);
	ft_put_kill(el, img, el->pos_x * 64 + 64, y);
}

void	ft_put_walk_right_kgrass(t_elements *el, t_images *img, int y, char p)
{
	if (p == 'p' || p == 'R' || p == 'r')
	{
		ft_put_player(el, img, el->pos_x * 64, y);
		mlx_do_sync(el->mlx);
		usleep(100000);
	}
	mlx_put_image_to_window(el->mlx, el->window, img->paccians1,
		el->pos_x * 64, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	ft_put_grass(el, img, el->pos_x * 64, y);
	ft_put_kill(el, img, el->pos_x * 64 + 64, y);
}

void	ft_put_walk_right_jail(t_elements *el, t_images *img, int y, char p)
{
	if (p == 'Q')
	{
		mlx_put_image_to_window(el->mlx, el->window, img->pacciansjail0,
			el->pos_x * 64, y);
		mlx_do_sync(el->mlx);
		usleep(100000);
	}
	mlx_put_image_to_window(el->mlx, el->window, img->pacciansjail1,
		el->pos_x * 64, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	ft_put_exit(el, img, el->pos_x * 64, y);
	mlx_put_image_to_window(el->mlx, el->window, img->paccians2,
		el->pos_x * 64 + 64, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	ft_put_player(el, img, el->pos_x * 64 + 64, y);
}

void	ft_put_walk_right_grass(t_elements *el, t_images *img, int y, char p)
{
	if (p == 'p' || p == 'R' || p == 'r')
	{
		ft_put_player(el, img, el->pos_x * 64, y);
		mlx_do_sync(el->mlx);
		usleep(100000);
	}
	mlx_put_image_to_window(el->mlx, el->window, img->paccians1,
		el->pos_x * 64, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	ft_put_grass(el, img, el->pos_x * 64, y);
	mlx_put_image_to_window(el->mlx, el->window, img->paccians2,
		el->pos_x * 64 + 64, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	ft_put_player(el, img, el->pos_x * 64 + 64, y);
}
