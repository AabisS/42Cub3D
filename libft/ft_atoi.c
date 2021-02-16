/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:05:15 by fmarckma          #+#    #+#             */
/*   Updated: 2019/10/25 10:05:17 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespace(const char *str, size_t i)
{
	if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	i = 0;
	while (whitespace(str, i) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (sign * result);
}
