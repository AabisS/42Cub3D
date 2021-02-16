/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structure2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:18:39 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/10 15:22:20 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_path_sprite(t_parse *info, char *str)
{
	int i;
	int j;

	j = 0;
	i = 1;
	i = down_space(str, i);
	while (str[i])
		info->text_s[j++] = str[i++];
	info->text_s[j] = '\0';
}

int		to_next_digit(int i, char *str)
{
	while (ft_isdigit(str[i]))
		i++;
	while (!ft_isdigit(str[i]))
		i++;
	return (i);
}

int		floor_color(t_parse *info, char *str, int c)
{
	int i;
	int nb1;
	int nb2;
	int nb3;

	i = 1;
	i = down_space(str, i);
	nb1 = ft_atoi(str + i);
	i = to_next_digit(i, str);
	nb2 = ft_atoi(str + i);
	i = to_next_digit(i, str);
	nb3 = ft_atoi(str + i);
	if (!verif_rgb(info, nb1, nb2, nb3))
		return (0);
	i = rgb_to_integer(nb1, nb2, nb3);
	if (c == 0)
		info->fcolor = i;
	else
		info->ccolor = i;
	return (1);
}
