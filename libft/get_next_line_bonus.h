/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:45:30 by stescaro          #+#    #+#             */
/*   Updated: 2023/11/03 10:45:31 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

typedef struct l_list
{
	int				fd;
	char			*ptr;
	struct l_list	*next;
}						t_fd_list;

char	*get_next_line(int fd);
char	*get_single_line(char *str);
char	*f_strjoin(char *s1, char *s2);
int		f_sl(char *c);
char	*free_and_null(char *to_free, char **to_null);

#endif
