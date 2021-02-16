/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:15:16 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/07 10:42:55 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	got_nl(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (1);
	return (0);
}

static void	get_and_save(char *line, char *save)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		line[i] = '\0';
		i++;
		while (line[i + j])
		{
			save[j] = line[i + j];
			j++;
		}
	}
	save[j] = '\0';
}

static int	checkerror(char **line, char *buffer, int fd)
{
	if (fd < 0 || fd > 10240 || BUFFER_SIZE < 1 || line == NULL)
		return (1);
	if (!(*line = malloc(sizeof(char))))
		return (1);
	*line[0] = '\0';
	buffer[0] = '\0';
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	save[10240][BUFFER_SIZE + 2];
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	if (checkerror(line, buffer, fd))
		return (-1);
	if (save[fd][BUFFER_SIZE + 1] != 54)
	{
		save[fd][0] = '\0';
		save[fd][BUFFER_SIZE + 1] = 54;
	}
	else
		*line = ft_strjoin_free(line, save[fd], 1);
	while (!(got_nl(*line)) && (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		*line = ft_strjoin_free(line, buffer, 1);
	}
	i = got_nl(*line);
	get_and_save(*line, save[fd]);
	if (!i || ret == -1 || fd == -1)
		save[fd][BUFFER_SIZE + 1] = '\0';
	return ((fd == -1 || i == -1 || ret == -1) ? -1 : i != 0);
}
