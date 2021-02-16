/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:05:36 by fmarckma          #+#    #+#             */
/*   Updated: 2019/10/25 10:05:40 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *dest;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(dest = malloc(size * count)))
		return (NULL);
	ft_bzero(dest, count * size);
	return (dest);
}
