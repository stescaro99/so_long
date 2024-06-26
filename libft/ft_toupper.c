/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:18:48 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/10 14:18:50 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
		return (c - 32);
	else
		return (c);
}

/*int main()
{
	printf("%c:%c\n", 70, ft_toupper(70));
	printf("%c:%c\n", 100, ft_toupper(100));
	return 0;
}*/
