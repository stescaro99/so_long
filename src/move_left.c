/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:55:24 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/22 12:05:04 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	left_grass(t_elements *el, char p, int x, int y)
{
	if (p == 'P' || p == 'p' || p == 'R' || p == 'r')
	{
		el->map[y][x] = '0';
		el->map[y][x - 1] = 'p';
		ft_put_walk_left_grass(el, el->img, (y * 64) + 32, p);
	}
	else if (p == 'Q' || p == 'q')
	{
		el->map[y][x] = 'E';
		el->map[y][x - 1] = 'p';
		ft_put_walk_left_jail(el, el->img, (y * 64) + 32, p);
	}
	el->pos_x -= 1;
}

static	void	left_coll(t_elements *el, char p, int x, int y)
{
	if (p == 'P' || p == 'p' || p == 'R' || p == 'r')
	{
		el->map[y][x] = '0';
		el->map[y][x - 1] = 'p';
		ft_put_walk_left_kgrass(el, el->img, (y * 64) + 32, p);
	}
	else if (p == 'Q' || p == 'q')
	{
		el->map[y][x] = 'E';
		el->map[y][x - 1] = 'p';
		ft_put_walk_left_kjail(el, el->img, (y * 64) + 32, p);
	}
	if (--(el->collectibles) == 0)
		ft_put_exit_open(el, el->img, el->map);
	el->pos_x -= 1;
}

static	void	left_exit(t_elements *el, char p, int x, int y)
{
	el->map[el->pos_y][el->pos_x] = '0';
	if (p == 'P' || p == 'R' || p == 'r')
	{
		ft_put_rev_player(el, el->img, x, y);
		mlx_do_sync(el->mlx);
		usleep(100000);
	}
	mlx_put_image_to_window(el->mlx, el->window, el->img->paccians1r, x, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	ft_put_grass(el, el->img, el->pos_x * 64, y);
	mlx_put_image_to_window(el->mlx, el->window, el->img->pacciansjail2r,
		x - 64, y);
	mlx_do_sync(el->mlx);
	usleep(150000);
	mlx_put_image_to_window(el->mlx, el->window, el->img->pacciansjail0r,
		x - 64, y);
	el->pos_x -= 1;
	el->map[el->pos_y][el->pos_x] = 'q';
}

void	ft_moveleft(t_elements *el, int x, int y)
{
	if (el->map[y][x - 1] == '1')
	{
		ft_invalid_movement(el);
		return ;
	}
	el->n_moves += 1;
	if (el->map[y][x - 1] == '0')
		left_grass(el, el->map[y][x], x, y);
	else if (el->map[y][x - 1] == 'C')
		left_coll(el, el->map[y][x], x, y);
	else if (el->map[y][x - 1] == 'E')
		left_exit(el, el->map[y][x], el->pos_x * 64, el->pos_y * 64 + 32);
	else if (el->map[y][x - 1] == 'e')
		ft_win(el, el->img, x - 1, y);
	else if (el->map[y][x - 1] == 'V')
	{
		if (el->map[y][x] == 'P' || el->map[y][x] == 'p'
			|| el->map[y][x] == 'R' || el->map[y][x] == 'r')
			ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		else if (el->map[y][x] == 'Q' || el->map[y][x] == 'q')
			ft_put_exit(el, el->img, x * 64, (y * 64) + 32);
		ft_lose(el, el->img, x - 1, y);
	}
}
