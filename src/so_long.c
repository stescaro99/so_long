/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:57:14 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/22 10:30:26 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_tile(t_elements *elements, int i, int j)
{
	long	x;
	long	y;

	x = j * 64;
	y = 32 + (i * 64);
	if (elements->map[i][j] == '1')
		ft_put_wall(elements, elements->img, x, y);
	else if (elements->map[i][j] == '0')
		ft_put_grass(elements, elements->img, x, y);
	else if (elements->map[i][j] == 'C')
		ft_put_coll(elements, elements->img, x, y);
	else if (elements->map[i][j] == 'E')
		ft_put_exit(elements, elements->img, x, y);
	else if (elements->map[i][j] == 'P')
		ft_put_player(elements, elements->img, x, y);
	else if (elements->map[i][j] == 'V')
		ft_put_enemy(elements, elements->img, x, y);
}

void	ft_gamestart(t_elements *elements)
{
	int	i;
	int	j;

	i = 0;
	while (i < elements->height)
	{
		j = 0;
		while (j < elements->base)
		{
			ft_put_tile(elements, i, j);
			j++;
		}
		i++;
	}
	ft_put_background(elements, elements->img);
}

int	ft_keyhook(int keysym, t_elements *el)
{
	el->key = keysym;
	if (keysym == XK_Escape || el->map[0][0] == '0')
		ft_closegame(el);
	if (el->key == XK_w || el->key == XK_Up || el->key == XK_W)
		ft_moveup(el, el->pos_x, el->pos_y);
	else if (el->key == XK_a || el->key == XK_Left || el->key == XK_A)
		ft_moveleft(el, el->pos_x, el->pos_y);
	else if (el->key == XK_s || el->key == XK_Down || el->key == XK_S)
		ft_movedown(el, el->pos_x, el->pos_y);
	else if (el->key == XK_d || el->key == XK_Right || el->key == XK_D)
		ft_moveright(el, el->pos_x, el->pos_y);
	ft_put_n_moves(el);
	return (0);
}

int	ft_closegame(t_elements *elements)
{
	ft_free_elem(elements);
	exit(0);
	return (1);
}

void	so_long(t_elements *elements)
{
	elements->mlx = mlx_init();
	if (!elements->mlx)
	{
		perror("Error!\nWindow initialization failed");
		exit(ft_free_elem(elements));
	}
	elements->window = mlx_new_window(elements->mlx, (64 * elements->base),
			(64 * elements->height) + 32, "so_long");
	if (!elements->window)
	{
		perror("Error!\nWindow initialization failed");
		exit(ft_free_elem(elements));
	}
	elements->img = set_img(elements, 64, 32);
	if (!elements->img)
	{
		perror("Error!\nimg allocation failed");
		exit(ft_free_elem(elements));
	}
	ft_gamestart(elements);
	mlx_key_hook(elements->window, &ft_keyhook, elements);
	mlx_hook(elements->window, 33, 1L << 5, &ft_closegame, elements);
	mlx_loop(elements->mlx);
}
