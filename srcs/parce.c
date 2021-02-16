/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:43:25 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/16 18:33:01 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		parse_parameter(char *line, t_parse *info_map)
{
	char *tmp;

	tmp = ft_strtrim(line, " ");
	if (tmp[0] == 'R' && (!fill_resolution(info_map, tmp)))
		return (0);
	else if ((tmp[0] == 'N' && tmp[1] == 'O'))
		fill_path_no(info_map, tmp);
	else if (tmp[0] == 'S' && tmp[1] == 'O')
		fill_path_so(info_map, tmp);
	else if (tmp[0] == 'W' && tmp[1] == 'E')
		fill_path_we(info_map, tmp);
	else if (tmp[0] == 'E' && tmp[1] == 'A')
		fill_path_ea(info_map, tmp);
	else if (tmp[0] == 'S' && tmp[1] == ' ')
		fill_path_sprite(info_map, tmp);
	else if (tmp[0] == 'F' && tmp[1] == ' ')
		floor_color(info_map, tmp, 0);
	else if (tmp[0] == 'C' && tmp[1] == ' ')
	{
		floor_color(info_map, tmp, 1);
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int		parse_av(char *av)
{
	int i;

	if (!av)
		return (1);
	i = ft_strlen(av);
	if (av[i - 4] != '.' || av[i - 3] != 'c' || av[i - 2] != 'u'
	|| av[i - 1] != 'b')
		return (1);
	else
		return (0);
}

int		read_files(t_parse *info_map, char *av, int fd)
{
	int		i;
	char	*line;
	char	*tmp_map;

	i = 1;
	add_nl_to_file(av);
	if (parse_av(av))
		return (error_manage2(9));
	else if (!(tmp_map = malloc(sizeof(char))))
		return (error_manage(5));
	while (get_next_line(fd, &line) == 1)
	{
		i = parse_parameter(line, info_map);
		free(line);
		if (i == 0)
			break ;
	}
	if (maping_parse(fd, line, info_map, tmp_map))
		return (1);
	return (0);
}

int		maping_parse(int fd, char *line, t_parse *info_map, char *tmp_map)
{
	int i;
	int j;

	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line && *line != '\n')
		{
			j++;
			tmp_map = ft_strjoin_more(tmp_map, line);
		}
		free(line);
	}
	free(line);
	i = 0;
	while (tmp_map[i++])
		if (tmp_map[i] == '2')
			info_map->sprite_nbr++;
	info_map->map = ft_split(tmp_map, '+');
	free(tmp_map);
	if (verif_map(info_map, j) || parse_map(info_map))
		return (1);
	if (verif_info(info_map))
		return (1);
	return (0);
}

void	get_pos_sprite(t_parse *info_map, t_storage *storage)
{
	int			y;
	int			x;
	int			n;

	y = 0;
	n = 0;
	while (info_map->map[y])
	{
		x = 0;
		while (info_map->map[y][x])
		{
			if (info_map->map[y][x] == '2')
			{
				storage->sprite[n].x = (double)x + 0.5;
				storage->sprite[n].y = (double)y + 0.5;
				n++;
			}
			x++;
		}
		y++;
	}
}
