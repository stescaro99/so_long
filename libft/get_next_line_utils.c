/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:34:51 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/30 16:01:38 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_previous(char *ptr)
{
	if (ptr == NULL)
		return ;
	while (*ptr != 127)
		(ptr)--;
	free(ptr);
}

char	*get_single_line(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	if (*str == '\0')
		return (NULL);
	new_str = malloc(f_sl(str) + (str[f_sl(str) - 1] == '\n'));
	if (new_str == NULL)
		return (NULL);
	while (str[++i] != '\0' && str[i] != '\n')
		new_str[i - 1] = str[i];
	if (i <= f_sl(str) && str[i] == '\n')
	{
		new_str[i - 1] = str[i];
		i++;
	}
	new_str[i - 1] = '\0';
	return (new_str);
}

char	*f_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		s1_len;
	int		s2_len;

	if (s1 != NULL && *s1 == 127)
		s1++;
	s1_len = f_sl(s1) + 1;
	s2_len = f_sl(s2);
	i = 0;
	newstr = malloc((s1_len + s2_len + 1));
	if (newstr == NULL)
		return (NULL);
	newstr[0] = 127;
	while (++i < s1_len)
		newstr[i] = s1[i - 1];
	i = -1;
	while (++i < s2_len)
		newstr[s1_len + i] = s2[i];
	newstr[s1_len + i] = '\0';
	free((void *)s2);
	free_previous((char *)s1);
	return (newstr);
}

int	f_sl(char *c)
{
	int	n;

	if (c == NULL)
		return (0);
	n = 0;
	while (c[n])
		n++;
	return (n);
}
