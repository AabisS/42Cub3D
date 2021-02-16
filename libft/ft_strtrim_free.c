/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:00:30 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/10 12:03:29 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	unsigned int i;

	if (!set)
		return (0);
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim_free(char *s1, char const *set)
{
	char			*start;
	char			*end;
	char			*ret;
	int				len;
	unsigned int	i;

	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1);
	while (is_set(*start, set))
		start++;
	if (start < end)
		end--;
	while (is_set(*end, set))
		end--;
	len = end - start + 1;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (len-- > 0)
		ret[i++] = *start++;
	ret[i] = '\0';
	free(s1);
	return (ret);
}