/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savepart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:16:42 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/16 18:08:25 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_struct_save(t_storage *storage, t_save *s)
{
	s->size = 54 + 4 * storage->info->width * storage->info->height;
	s->unused = 0;
	s->offset_begin = 54;
	s->header_bytes = 40;
	s->plane = 1;
	s->bpixel = 32;
	s->fd = open("img.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
	if (s->fd == -1)
		ft_putstr_fd("Error: Cannot open file .bmp\n", 1);
}

void		write_texture_bmp_file(t_storage *storage, int fd)
{
	int		y;
	int		x;
	int		line;

	y = 0;
	while (y < storage->info->height)
	{
		x = 0;
		line = storage->info->width * (storage->info->height - y);
		while (x < storage->info->width)
		{
			write(fd, &storage->mlx->data_img[line * 4], 4);
			line++;
			x++;
		}
		y++;
	}
}

void		write_bmp_file(t_storage *storage)
{
	t_save	s;

	storage->info->to_save = 0;
	init_struct_save(storage, &s);
	write(s.fd, "BM", 2);
	write(s.fd, &s.size, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.offset_begin, sizeof(int));
	write(s.fd, &s.header_bytes, sizeof(int));
	write(s.fd, &storage->info->width, sizeof(int));
	write(s.fd, &storage->info->height, sizeof(int));
	write(s.fd, &s.plane, sizeof(short int));
	write(s.fd, &s.bpixel, sizeof(short int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write_texture_bmp_file(storage, s.fd);
	close(s.fd);
}
