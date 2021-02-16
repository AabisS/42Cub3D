/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 22:19:45 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/16 18:34:53 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_nl_to_file(char *av)
{
	int fd;

	fd = open(av, O_WRONLY | O_APPEND);
	write(fd, "\n", 1);
	close(fd);
}

int		down_space_reverse(char *str, int i)
{
	while (str[i] == ' ')
		i--;
	return (i);
}

void	free_3str(char *s1, char *s2, char *s3)
{
	free(s1);
	free(s2);
	free(s3);
}

int		got_space(char *str)
{
	int i;

	i = 0;
	while (str[i++])
		if (str[i] == ' ')
		{
			free(str);
			return (1);
		}
	free(str);
	return (0);
}

int		map_first_last_line(char *str)
{
	int i;

	i = 0;
	while (str[i++])
		if (str[i] && str[i] != '1' && str[i] != ' ')
			return (1);
	return (0);
}
