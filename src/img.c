/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:41 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/22 16:16:30 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_free_img_2(t_elements *elem, t_images **img)
{
	if ((*img)->wall)
		mlx_destroy_image(elem->mlx, (*img)->wall);
	if ((*img)->moves_background)
		mlx_destroy_image(elem->mlx, (*img)->moves_background);
	if ((*img)->lose)
		mlx_destroy_image(elem->mlx, (*img)->lose);
	if ((*img)->killingr)
		mlx_destroy_image(elem->mlx, (*img)->killingr);
	if ((*img)->killing)
		mlx_destroy_image(elem->mlx, (*img)->killing);
	if ((*img)->jailopen)
		mlx_destroy_image(elem->mlx, (*img)->jailopen);
	if ((*img)->jailclose)
		mlx_destroy_image(elem->mlx, (*img)->jailclose);
	if ((*img)->grass)
		mlx_destroy_image(elem->mlx, (*img)->grass);
	if ((*img)->couple)
		mlx_destroy_image(elem->mlx, (*img)->couple);
	if ((*img)->cop)
		mlx_destroy_image(elem->mlx, (*img)->cop);
	if ((*img)->gameover)
		mlx_destroy_image(elem->mlx, (*img)->gameover);
	if ((*img)->win)
		mlx_destroy_image(elem->mlx, (*img)->win);
}

void	ft_free_img(t_elements *elem, t_images **img)
{
	if ((*img)->paccians0)
		mlx_destroy_image(elem->mlx, (*img)->paccians0);
	if ((*img)->paccians0r)
		mlx_destroy_image(elem->mlx, (*img)->paccians0r);
	if ((*img)->paccians1)
		mlx_destroy_image(elem->mlx, (*img)->paccians1);
	if ((*img)->paccians1r)
		mlx_destroy_image(elem->mlx, (*img)->paccians1r);
	if ((*img)->paccians2)
		mlx_destroy_image(elem->mlx, (*img)->paccians2);
	if ((*img)->paccians2r)
		mlx_destroy_image(elem->mlx, (*img)->paccians2r);
	if ((*img)->pacciansjail0)
		mlx_destroy_image(elem->mlx, (*img)->pacciansjail0);
	if ((*img)->pacciansjail0r)
		mlx_destroy_image(elem->mlx, (*img)->pacciansjail0r);
	if ((*img)->pacciansjail1)
		mlx_destroy_image(elem->mlx, (*img)->pacciansjail1);
	if ((*img)->pacciansjail1)
		mlx_destroy_image(elem->mlx, (*img)->pacciansjail1r);
	if ((*img)->pacciansjail2)
		mlx_destroy_image(elem->mlx, (*img)->pacciansjail2);
	if ((*img)->pacciansjail2r)
		mlx_destroy_image(elem->mlx, (*img)->pacciansjail2r);
	ft_free_img_2(elem, img);
}

static	void	set_img_3(t_elements *elem, t_images **img, int s)
{
	(*img)->gameover = mlx_xpm_file_to_image(elem->mlx,
			"./img/gameover.xpm", &s, &s);
	(*img)->win = mlx_xpm_file_to_image(elem->mlx, "./img/win.xpm", &s, &s);
	if (!((*img)->win))
	{
		perror("Error!\nImages allocation failed");
		exit(ft_free_elem(elem));
	}
}

static	void	set_img_2(t_elements *elem, t_images **img, int *s)
{
	(*img)->paccians1 = mlx_xpm_file_to_image(elem->mlx,
			"./img/paccians1.xpm", s, s);
	(*img)->paccians1r = mlx_xpm_file_to_image(elem->mlx,
			"./img/paccians1r.xpm", s, s);
	(*img)->paccians2 = mlx_xpm_file_to_image(elem->mlx,
			"./img/paccians2.xpm", s, s);
	(*img)->paccians2r = mlx_xpm_file_to_image(elem->mlx,
			"./img/paccians2r.xpm", s, s);
	(*img)->pacciansjail0 = mlx_xpm_file_to_image(elem->mlx,
			"./img/pacciansjail0.xpm", s, s);
	(*img)->pacciansjail0r = mlx_xpm_file_to_image(elem->mlx,
			"./img/pacciansjail0r.xpm", s, s);
	(*img)->pacciansjail1 = mlx_xpm_file_to_image(elem->mlx,
			"./img/pacciansjail1.xpm", s, s);
	(*img)->pacciansjail1r = mlx_xpm_file_to_image(elem->mlx,
			"./img/pacciansjail1r.xpm", s, s);
	(*img)->pacciansjail2 = mlx_xpm_file_to_image(elem->mlx,
			"./img/pacciansjail2.xpm", s, s);
	(*img)->pacciansjail2r = mlx_xpm_file_to_image(elem->mlx,
			"./img/pacciansjail2r.xpm", s, s);
	(*img)->wall = mlx_xpm_file_to_image(elem->mlx, "./img/wall.xpm", s, s);
	set_img_3(elem, img, 256);
}

t_images	*set_img(t_elements *elem, int s, int t)
{
	t_images	*img;

	img = malloc(sizeof(t_images));
	if (!img)
		return (NULL);
	img->cop = mlx_xpm_file_to_image(elem->mlx, "./img/cop.xpm", &s, &s);
	img->couple = mlx_xpm_file_to_image(elem->mlx, "./img/couple.xpm", &s, &s);
	img->grass = mlx_xpm_file_to_image(elem->mlx, "./img/grass.xpm", &s, &s);
	img->jailclose = mlx_xpm_file_to_image(elem->mlx,
			"./img/jailclose.xpm", &s, &s);
	img->jailopen = mlx_xpm_file_to_image(elem->mlx,
			"./img/jailopen.xpm", &s, &s);
	img->killing = mlx_xpm_file_to_image(elem->mlx,
			"./img/killing.xpm", &s, &s);
	img->killingr = mlx_xpm_file_to_image(elem->mlx,
			"./img/killingr.xpm", &s, &s);
	img->lose = mlx_xpm_file_to_image(elem->mlx, "./img/lose.xpm", &s, &s);
	img->moves_background = mlx_xpm_file_to_image(elem->mlx,
			"./img/moves_background.xpm", &t, &t);
	img->paccians0 = mlx_xpm_file_to_image(elem->mlx,
			"./img/paccians0.xpm", &s, &s);
	img->paccians0r = mlx_xpm_file_to_image(elem->mlx,
			"./img/paccians0r.xpm", &s, &s);
	set_img_2(elem, &img, &s);
	return (img);
}
