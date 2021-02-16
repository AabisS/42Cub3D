/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:42:06 by fmarckma          #+#    #+#             */
/*   Updated: 2019/10/25 09:46:28 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *d, int c, size_t len)
{
	unsigned char	*buf;
	unsigned char	ch;

	buf = (unsigned char *)d;
	ch = (unsigned char)c;
	while (len-- > 0)
		*buf++ = ch;
	return (d);
}
