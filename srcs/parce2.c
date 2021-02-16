/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:49:57 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/10 13:44:53 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		parse_map(t_parse *info_map)
{
	int i;
	int k;

	k = 0;
	while (info_map->map[k])
	{
		i = 0;
		while (info_map->map[k][i])
		{
			if (info_map->map[k][i] == 'N' || info_map->map[k][i] == 'S'
			|| info_map->map[k][i] == 'W' || info_map->map[k][i] == 'E')
			{
				info_map->start = info_map->map[k][i];
				info_map->map[k][i] = '0';
				info_map->player_x = i;
				info_map->player_y = k;
				if (info_map->err++ >= 1)
					return (error_manage2(12));
			}
			i++;
		}
		k++;
	}
	return (0);
}

int		first_char(char *str, char *prev, char *next)
{
	int		i;
	int		j;
	int		d;

	d = 0;
	j = 0;
	i = 0;
	j = down_space(prev, j);
	i = down_space(next, i);
	d = down_space(str, d);
	if (str[d] != '1')
	{
		if (prev[j] == '1' && prev[j + 1] == '1' && str[d + 1] == '1' &&
		next[i] == '1' && next[i + 1] == '1')
			return (0);
		return (1);
	}
	return (0);
}

int		last_char(char *str, char *prev, char *next)
{
	int		i;
	int		j;
	int		d;

	d = ft_strlen(str);
	j = ft_strlen(prev);
	i = ft_strlen(next);
	j = down_space_reverse(prev, j);
	i = down_space_reverse(next, i);
	d = down_space_reverse(str, d);
	if (str[d - 1] != '1')
	{
		if (prev[j - 1] == '1' && prev[j - 2] == '1' && str[d - 2] == '1' &&
		next[i - 1] == '1' && next[i - 2] == '1')
			return (0);
		return (1);
	}
	return (0);
}

int		check_between_line(char *prev, char *actual, char *next)
{
	int i;

	i = 0;
	while (actual[i++])
		if (actual[i] == ' ')
			break ;
	while (actual[i] == ' ')
	{
		if (prev[i - 1] == '0' || prev[i] == '0' || prev[i + 1] == '0' ||
		actual[i - 1] == '0' || actual[i + 1] == '0' ||
		next[i - 1] == '0' || next[i] == '0' || next[i + 1] == '0')
		{
			free_3str(prev, actual, next);
			return (1);
		}
		i++;
	}
	free_3str(prev, actual, next);
	return (0);
}

int		verif_map(t_parse *info, int j)
{
	int i;

	i = 1;
	if (map_first_last_line(info->map[0]) ||
	map_first_last_line(info->map[j - 1]))
		return (error_manage3(16));
	while (i < j - 1)
	{
		if (first_char(info->map[i], info->map[i - 1], info->map[i + 1]) ||
		last_char(info->map[i], info->map[i - 1], info->map[i + 1]))
			return (error_manage2(11));
		if (got_space(ft_strtrim(info->map[i], " ")) &&
		check_between_line(ft_strtrim(info->map[i - 1], " "),
		ft_strtrim(info->map[i], " "), ft_strtrim(info->map[i + 1], " ")))
			return (error_manage2(11));
		i++;
	}
	return (0);
}
