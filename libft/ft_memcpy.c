/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:47:01 by fmarckma          #+#    #+#             */
/*   Updated: 2019/10/25 09:47:05 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (i < n)
	{
		*(dest + i) = *(source + i);
		i++;
	}
	return (dst);
}
