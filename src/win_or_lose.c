/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_or_lose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:11:03 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/22 11:32:55 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_exit_open(t_elements *el, t_images *img, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < el->height)
	{
		j = 0;
		while (++j < el->base)
		{
			if (map[i][j] == 'E')
				break ;
		}
		if (j != el->base)
			break ;
	}
	el->map[i][j] = 'e';
	mlx_put_image_to_window(el->mlx, el->window, img->jailopen,
		j * 64, (i * 64) + 32);
}

void	ft_win(t_elements *el, t_images *img, int x, int y)
{
	if (el->base < 4 || el->height < 4)
		ft_closegame(el);
	if (el->key == XK_Up || el->key == XK_w || el->key == XK_W)
		mlx_put_image_to_window(el->mlx, el->window,
			img->grass, x * 64, ((y + 1) * 64) + 32);
	if (el->key == XK_Down || el->key == XK_s || el->key == XK_S)
		mlx_put_image_to_window(el->mlx, el->window,
			img->grass, x * 64, ((y - 1) * 64) + 32);
	if (el->key == XK_Left || el->key == XK_a || el->key == XK_A)
		mlx_put_image_to_window(el->mlx, el->window,
			img->grass, (x + 1) * 64, (y * 64) + 32);
	if (el->key == XK_Right || el->key == XK_d || el->key == XK_D)
		mlx_put_image_to_window(el->mlx, el->window,
			img->grass, (x - 1) * 64, (y * 64) + 32);
	mlx_put_image_to_window(el->mlx, el->window,
		img->pacciansjail1, x * 64, (y * 64) + 32);
	mlx_do_sync(el->mlx);
	el->map[0][0] = '0';
	x = ((el->base * 64) - 256) / 2;
	y = ((el->height * 64) - 224) / 2;
	mlx_put_image_to_window(el->mlx, el->window, img->win, x, y);
	sleep(1);
}

void	ft_lose(t_elements *el, t_images *img, int x, int y)
{
	if (el->base < 4 || el->height < 4)
		ft_closegame(el);
	mlx_put_image_to_window(el->mlx, el->window,
		img->lose, x * 64, (y * 64) + 32);
	mlx_do_sync(el->mlx);
	el->map[0][0] = '0';
	x = ((el->base * 64) - 256) / 2;
	y = ((el->height * 64) - 224) / 2;
	mlx_put_image_to_window(el->mlx, el->window,
		img->gameover, x, y);
	sleep(3);
}
