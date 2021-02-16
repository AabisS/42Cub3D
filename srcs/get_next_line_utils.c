/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:37:04 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/16 18:20:56 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char **s1, char *s2, int k)
{
	size_t	i;
	size_t	j;
	char	*cpy_s1;
	char	*cpy_s2;
	char	*out;

	cpy_s1 = (char *)*s1;
	cpy_s2 = (char *)s2;
	i = ft_strlen(cpy_s1);
	j = ft_strlen(cpy_s2);
	if (!(out = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = -1;
	while (cpy_s1[++i])
		out[i] = cpy_s1[i];
	j = 0;
	while (cpy_s2[j])
		out[i++] = cpy_s2[j++];
	out[i] = '\0';
	if (k == 1)
		free(*s1);
	else if (k == 0)
		free(s2);
	return (out);
}
