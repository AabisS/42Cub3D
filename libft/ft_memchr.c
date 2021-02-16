/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:48:58 by fmarckma          #+#    #+#             */
/*   Updated: 2019/10/25 09:49:00 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	size_t			i;

	ps = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (ps[i] == (unsigned char)c)
			return (ps + i);
		i++;
	}
	return (0);
}
