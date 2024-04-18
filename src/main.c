/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:58:27 by stescaro          #+#    #+#             */
/*   Updated: 2024/01/16 14:25:55 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char		**map;
	int			base;
	int			height;
	int			collectibles;
	t_elements	elements;

	if (argc != 2)
		return (perror("Error!\nInvalid number of arguments"), 1);
	map = set_map(argv[1]);
	height = -1;
	base = 0;
	collectibles = 0;
	if (!check_map(map, &height, &base, &collectibles))
		return (perror("Error!\nInvalid map: Wrong elements"),
			ft_freesplit(map));
	if (!check_dimensions(map, height, base))
		return (perror("Error!\nInvalid map: Dimensions error"),
			ft_freesplit(map));
	elements = set_elements(base, height, collectibles, map);
	if (!check_winnable_map(map, elements))
		return (perror("Error!\nInvalid map: You can't win on this map"),
			ft_free_elem(&elements));
	so_long(&elements);
	return (0);
}
