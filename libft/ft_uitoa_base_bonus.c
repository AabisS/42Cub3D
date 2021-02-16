/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:35:44 by vsteyaer          #+#    #+#             */
/*   Updated: 2019/11/25 12:03:21 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_digitlen_base(__uintmax_t n, int baselen)
{
	__uintmax_t	ret;

	ret = 0;
	while (n != 0)
	{
		n = n / baselen;
		ret++;
	}
	return (ret);
}

char			*ft_uitoa_base(__uintmax_t n, int baselen, char *base)
{
	__uintmax_t		len;
	__uintmax_t		i;
	char			*str;

	i = 0;
	len = ft_digitlen_base(n, baselen);
	if (!(str = malloc(sizeof(char) * len + 2)))
		return (NULL);
	if (n == 0)
		return (ft_strcpy(str, "0"));
	str[len] = '\0';
	while (len > i)
	{
		str[--len] = base[n % baselen];
		n = n / baselen;
	}
	return (str);
}
