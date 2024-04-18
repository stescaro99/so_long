/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:48:13 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/22 14:02:33 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_exit(t_elements *el, char p, int x, int y)
{
	el->map[y][x] = '0';
	if (p == 'R')
		ft_put_player(el, el->img, x * 64, (y * 64) + 32);
	else if (p == 'r')
		ft_put_rev_player(el, el->img, x * 64, (y * 64) + 32);
	if (p == 'P' || p == 'R')
	{
		el->map[y - 1][x] = 'Q';
		ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		ft_put_pinj(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
	else if (p == 'p' || p == 'r')
	{
		el->map[y - 1][x] = 'q';
		ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		ft_put_rev_pinj(el, el->img, x * 64, ((y - 1) * 64) + 32);
	}
	el->pos_y -= 1;
}

void	down_exit(t_elements *el, char p, int x, int y)
{
	el->map[y][x] = '0';
	if (p == 'R')
		ft_put_player(el, el->img, x * 64, (y * 64) + 32);
	else if (p == 'r')
		ft_put_rev_player(el, el->img, x * 64, (y * 64) + 32);
	if (p == 'P' || p == 'R')
	{
		el->map[y + 1][x] = 'Q';
		ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		ft_put_pinj(el, el->img, x * 64, ((y + 1) * 64) + 32);
	}
	else if (p == 'p' || p == 'r')
	{
		el->map[y + 1][x] = 'q';
		ft_put_grass(el, el->img, x * 64, (y * 64) + 32);
		ft_put_rev_pinj(el, el->img, x * 64, ((y + 1) * 64) + 32);
	}
	el->pos_y += 1;
}
