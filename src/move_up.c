/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:52:32 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/22 13:58:03 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	up_grass_2(t_elements *el, char p, int x, int y)
{
	if (p == 'R')
	{
		el->map[y][x] = '0';
		el->map[y - 1][x] = 'P';
		ft_put_player(el, el->img, x * 64, (y * 64) + 32);
		ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		ft_put_player(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
	else if (p == 'r')
	{
		el->map[y][x] = '0';
		el->map[y - 1][x] = 'p';
		ft_put_rev_player(el, el->img, x * 64, (y * 64) + 32);
		ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		ft_put_rev_player(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
	else if (p == 'q')
	{
		el->map[y][x] = 'E';
		el->map[y - 1][x] = 'p';
		ft_put_exit(el, el->img, x * 64, (y * 64) + 32);
		ft_put_rev_player(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
}

static	void	up_grass(t_elements *el, char p, int x, int y)
{
	if (p == 'P')
	{
		el->map[y][x] = '0';
		el->map[y - 1][x] = 'P';
		ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		ft_put_player(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
	else if (p == 'p')
	{
		el->map[y][x] = '0';
		el->map[y - 1][x] = 'p';
		ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		ft_put_rev_player(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
	else if (p == 'Q')
	{
		el->map[y][x] = 'E';
		el->map[y - 1][x] = 'P';
		ft_put_exit(el, el->img, x * 64, (y * 64) + 32);
		ft_put_player(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
	else
		up_grass_2(el, p, x, y);
	el->pos_y -= 1;
}

static	void	up_coll_2(t_elements *el, char p, int x, int y)
{
	if (p == 'R')
	{
		el->map[y][x] = '0';
		el->map[y - 1][x] = 'R';
		ft_put_player(el, el->img, x * 64, (y * 64) + 32);
		ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		ft_put_kill(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
	else if (p == 'r')
	{
		el->map[y][x] = '0';
		el->map[y - 1][x] = 'r';
		ft_put_rev_player(el, el->img, x * 64, (y * 64) + 32);
		ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		ft_put_rev_kill(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
	else if (p == 'q')
	{
		el->map[y][x] = 'E';
		el->map[y - 1][x] = 'p';
		ft_put_exit(el, el->img, x * 64, (y * 64) + 32);
		ft_put_rev_kill(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
	if (--(el->collectibles) == 0)
		ft_put_exit_open(el, el->img, el->map);
}

static	void	up_coll(t_elements *el, char p, int x, int y)
{
	if (p == 'P')
	{
		el->map[y][x] = '0';
		el->map[y - 1][x] = 'R';
		ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		ft_put_kill(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
	else if (p == 'p')
	{
		el->map[y][x] = '0';
		el->map[y - 1][x] = 'r';
		ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		ft_put_rev_kill(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
	else if (p == 'Q')
	{
		el->map[y][x] = 'E';
		el->map[y - 1][x] = 'R';
		ft_put_exit(el, el->img, x * 64, (y * 64) + 32);
		ft_put_player(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
	up_coll_2(el, p, x, y);
	el->pos_y -= 1;
}

void	ft_moveup(t_elements *el, int x, int y)
{
	if (el->map[y - 1][x] == '1')
	{
		ft_invalid_movement(el);
		return ;
	}
	el->n_moves += 1;
	if (el->map[y - 1][x] == '0')
		up_grass(el, el->map[y][x], x, y);
	else if (el->map[y - 1][x] == 'C')
		up_coll(el, el->map[y][x], x, y);
	else if (el->map[y - 1][x] == 'E')
		up_exit(el, el->map[y][x], x, y);
	else if (el->map[y - 1][x] == 'e')
		ft_win(el, el->img, x, y - 1);
	else if (el->map[y - 1][x] == 'V')
	{
		if (el->map[y][x] == 'P' || el->map[y][x] == 'p'
			|| el->map[y][x] == 'R' || el->map[y][x] == 'r')
			ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		else if (el->map[y][x] == 'Q' || el->map[y][x] == 'q')
			ft_put_exit(el, el->img, x * 64, (y * 64) + 32);
		ft_lose(el, el->img, x, y - 1);
	}
}
