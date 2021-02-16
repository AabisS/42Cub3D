/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:47:17 by fmarckma          #+#    #+#             */
/*   Updated: 2019/10/25 09:47:34 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	stop_c;
	size_t			i;
	unsigned char	*str_dst;
	unsigned char	*str_src;

	stop_c = (unsigned char)c;
	str_dst = (unsigned char*)dst;
	str_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		*(str_dst + i) = *(str_src + i);
		if (*(str_src + i) == stop_c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
