/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:53:09 by fmarckma          #+#    #+#             */
/*   Updated: 2019/10/25 09:53:11 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*start;
	char	*cur;

	start = (char*)s;
	cur = start;
	while (*cur != '\0')
		cur++;
	while (cur >= start)
	{
		if (*cur == (char)c)
			return (cur);
		cur--;
	}
	return (0);
}
