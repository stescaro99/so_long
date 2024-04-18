/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_walk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:13:01 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/22 12:08:16 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_walk_left_kjail(t_elements *el, t_images *img, int y, char p)
{
	if (p == 'Q')
	{
		mlx_put_image_to_window(el->mlx, el->window, img->pacciansjail0r,
			el->pos_x * 64, y);
		mlx_do_sync(el->mlx);
		usleep(100000);
	}
	mlx_put_image_to_window(el->mlx, el->window, img->pacciansjail1r,
		el->pos_x * 64, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	ft_put_exit(el, img, el->pos_x * 64, y);
	ft_put_rev_kill(el, img, el->pos_x * 64 - 64, y);
}

void	ft_put_walk_left_kgrass(t_elements *el, t_images *img, int y, char p)
{
	if (p == 'P' || p == 'R' || p == 'r')
	{
		ft_put_rev_player(el, img, el->pos_x * 64, y);
		mlx_do_sync(el->mlx);
		usleep(100000);
	}
	mlx_put_image_to_window(el->mlx, el->window, img->paccians1r,
		el->pos_x * 64, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	ft_put_grass(el, img, el->pos_x * 64, y);
	ft_put_rev_kill(el, img, el->pos_x * 64 - 64, y);
}

void	ft_put_walk_left_jail(t_elements *el, t_images *img, int y, char p)
{
	if (p == 'Q')
	{
		mlx_put_image_to_window(el->mlx, el->window, img->pacciansjail0r,
			el->pos_x * 64, y);
		mlx_do_sync(el->mlx);
		usleep(100000);
	}
	mlx_put_image_to_window(el->mlx, el->window, img->pacciansjail1r,
		el->pos_x * 64, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	ft_put_exit(el, img, el->pos_x * 64, y);
	mlx_put_image_to_window(el->mlx, el->window, img->paccians2r,
		el->pos_x * 64 - 64, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	ft_put_rev_player(el, img, el->pos_x * 64 - 64, y);
}

void	ft_put_walk_left_grass(t_elements *el, t_images *img, int y, char p)
{
	if (p == 'P' || p == 'R' || p == 'r')
	{
		ft_put_rev_player(el, img, el->pos_x * 64, y);
		mlx_do_sync(el->mlx);
		usleep(100000);
	}
	mlx_put_image_to_window(el->mlx, el->window, img->paccians1r,
		el->pos_x * 64, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	ft_put_grass(el, img, el->pos_x * 64, y);
	mlx_put_image_to_window(el->mlx, el->window, img->paccians2r,
		el->pos_x * 64 - 64, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	ft_put_rev_player(el, img, el->pos_x * 64 - 64, y);
}
