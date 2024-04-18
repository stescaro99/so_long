/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:12:07 by sfabi             #+#    #+#             */
/*   Updated: 2024/01/22 10:29:56 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"

typedef struct s_images
{
	void	*cop;
	void	*couple;
	void	*grass;
	void	*jailclose;
	void	*jailopen;
	void	*killing;
	void	*killingr;
	void	*lose;
	void	*moves_background;
	void	*paccians0;
	void	*paccians0r;
	void	*paccians1;
	void	*paccians1r;
	void	*paccians2;
	void	*paccians2r;
	void	*pacciansjail0;
	void	*pacciansjail0r;
	void	*pacciansjail1;
	void	*pacciansjail1r;
	void	*pacciansjail2;
	void	*pacciansjail2r;
	void	*wall;
	void	*gameover;
	void	*win;
}	t_images;

typedef struct s_elements
{
	int				base;
	int				height;
	int				villain;
	int				collectibles;
	int				pos_x;
	int				pos_y;
	int				n_moves;
	char			**map;
	int				key;
	void			*mlx;
	void			*window;
	struct s_images	*img;
}	t_elements;

int			check_map(char **map, int *height, int *base, int *collectibles);
int			check_dimensions(char **map, int height, int base);
int			check_winnable_map(char **map, t_elements elements);
char		**set_map(char *mapname);
int			ft_freesplit(char **split);
char		**ft_matrixcpy(char **matrix, int y);
t_elements	set_elements(int base, int height, int collectibles, char **map);
int			*set_elem(char **map, int height, int base);
void		so_long(t_elements *elements);
int			ft_free_elem(t_elements *elem);
int			ft_closegame(t_elements *elements);
t_images	*set_img(t_elements *elem, int s, int t);
void		ft_free_img(t_elements *elem, t_images **img);
void		ft_gamestart(t_elements *elements);
void		ft_put_background(t_elements *elements, t_images *img);
void		ft_put_n_moves(t_elements *elements);
void		ft_put_player(t_elements *elements, t_images *img, int x, int y);
void		ft_put_wall(t_elements *elements, t_images *img, int x, int y);
void		ft_put_grass(t_elements *elements, t_images *img, int x, int y);
void		ft_put_coll(t_elements *elements, t_images *img, int x, int y);
void		ft_put_exit(t_elements *elements, t_images *img, int x, int y);
void		ft_put_enemy(t_elements *elements, t_images *img, int x, int y);
void		ft_moveup(t_elements *el, int x, int y);
void		up_exit(t_elements *el, char p, int x, int y);
void		ft_put_rev_player(t_elements *elem, t_images *img, int x, int y);
void		ft_put_kill(t_elements *elements, t_images *img, int x, int y);
void		ft_put_rev_kill(t_elements *elements, t_images *img, int x, int y);
void		ft_put_pinj(t_elements *elements, t_images *img, int x, int y);
void		ft_put_rev_pinj(t_elements *elements, t_images *img, int x, int y);
void		ft_put_exit_open(t_elements *el, t_images *img, char **map);
void		ft_win(t_elements *el, t_images *img, int x, int y);
void		ft_lose(t_elements *el, t_images *img, int x, int y);
void		ft_movedown(t_elements *el, int x, int y);
void		down_exit(t_elements *el, char p, int x, int y);
void		ft_invalid_movement(t_elements *el);
void		ft_moveleft(t_elements *el, int x, int y);
void		ft_put_walk_left_grass(t_elements *el,
				t_images *img, int y, char p);
void		ft_put_walk_left_jail(t_elements *el, t_images *img, int y, char p);
void		ft_put_walk_left_kgrass(t_elements *el,
				t_images *img, int y, char p);
void		ft_put_walk_left_kjail(t_elements *el,
				t_images *img, int y, char p);
void		ft_moveright(t_elements *el, int x, int y);
void		ft_put_walk_right_grass(t_elements *el,
				t_images *img, int y, char p);
void		ft_put_walk_right_jail(t_elements *el,
				t_images *img, int y, char p);
void		ft_put_walk_right_kgrass(t_elements *el,
				t_images *img, int y, char p);
void		ft_put_walk_right_kjail(t_elements *el,
				t_images *img, int y, char p);

#endif
