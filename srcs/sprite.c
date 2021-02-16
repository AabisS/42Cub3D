/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:27:07 by jereligi          #+#    #+#             */
/*   Updated: 2021/02/16 18:08:25 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_texture(t_storage *s, t_sprite_info *s_i)
{
	int	stp;
	int	y;

	stp = s_i->drawstart_x;
	while (stp < s_i->drawend_x)
	{
		s_i->texx = (int)((256 * (stp - (-s_i->width / 2 + s_i->screen_x))
		* s_i->texwidth / s_i->width) / 256);
		y = s_i->drawstart_y;
		while (y < s_i->drawend_y && s_i->transformy > 0 && s_i->transformy
		< s->zbuffer[stp])
		{
			s_i->d = y * 256 - s->info->height * 128 + s_i->height * 128;
			s_i->texy = ((s_i->d * s_i->texheight) / s_i->height) / 256;
			if (s->texture[4].img[s_i->texy % 64 * s->texture[4].size_line
			+ s_i->texx % 64 * s->texture[4].bpixel / 8] != 0)
			{
				ft_memcpy(s->mlx->data_img + 4 * s->info->width * y + stp * 4,
				&s->texture[4].img[s_i->texy % 64 * s->texture[4].size_line +
				s_i->texx % 64 * s->texture[4].bpixel / 8], sizeof(int));
			}
			y++;
		}
		stp++;
	}
}

void	draw_sprite(t_sprite_info *s_i, t_sprite *sprite, int *sprite_order,
t_storage *s)
{
	s_i->x = sprite[sprite_order[s_i->i]].x - s->player->pos_x;
	s_i->y = sprite[sprite_order[s_i->i]].y - s->player->pos_y;
	s_i->inv_det = 1.0 / (s->ray->plane_x * s->player->dir_y -
	s->player->dir_x * s->ray->plane_y);
	s_i->transformx = s_i->inv_det * (s->player->dir_y * s_i->x -
	s->player->dir_x * s_i->y);
	s_i->transformy = s_i->inv_det * (-s->ray->plane_y * s_i->x +
	s->ray->plane_x * s_i->y);
	s_i->screen_x = (int)((s->info->width / 2) * (1 + s_i->transformx /
	s_i->transformy));
	s_i->height = abs((int)(s->info->height / (s_i->transformy)));
	s_i->drawstart_y = -s_i->height / 2 + s->info->height / 2;
	if (s_i->drawstart_y < 0)
		s_i->drawstart_y = 0;
	s_i->drawend_y = s_i->height / 2 + s->info->height / 2;
	if (s_i->drawend_y >= s->info->height)
		s_i->drawend_y = s->info->height - 1;
	s_i->width = abs((int)(s->info->height / (s_i->transformy)));
	s_i->drawstart_x = -s_i->width / 2 + s_i->screen_x;
	if (s_i->drawstart_x < 0)
		s_i->drawstart_x = 0;
	s_i->drawend_x = s_i->width / 2 + s_i->screen_x;
	if (s_i->drawend_x >= s->info->width)
		s_i->drawend_x = s->info->width - 1;
}

void	sort_sprites(int *sprite_order, double *sprite_distance,
int sprite_nb)
{
	int		i;
	int		tmp_order;
	double	tmp_dist;

	i = 0;
	while (i < sprite_nb - 1)
	{
		if (sprite_distance[i] > sprite_distance[i + 1])
		{
			tmp_dist = sprite_distance[i];
			sprite_distance[i] = sprite_distance[i + 1];
			sprite_distance[i + 1] = tmp_dist;
			tmp_order = sprite_order[i];
			sprite_order[i] = sprite_order[i + 1];
			sprite_order[i + 1] = tmp_order;
			i = -1;
		}
		i++;
	}
}

void	init_sprite(t_storage *s, t_sprite *sprite, int *sprite_order,
double *sprite_distance)
{
	int		i;

	i = 0;
	while (i < s->info->sprite_nbr)
	{
		sprite_distance[i] = ((s->player->pos_x - sprite[i].x) *
		(s->player->pos_x - sprite[i].x) + (s->player->pos_y - sprite[i].y)
		* (s->player->pos_y - sprite[i].y));
		sprite_order[i] = i;
		i++;
	}
	sort_sprites(sprite_order, sprite_distance, s->info->sprite_nbr);
}

void	management_sprite(t_storage *s, t_sprite *sprite, int sprite_nb)
{
	int					sprite_order[sprite_nb];
	double				sprite_distance[sprite_nb];
	t_sprite_info		s_i;

	init_sprite(s, sprite, sprite_order, sprite_distance);
	s_i.texwidth = 64;
	s_i.texheight = 64;
	s_i.i = sprite_nb - 1;
	while (s_i.i >= 0)
	{
		draw_sprite(&s_i, sprite, sprite_order, s);
		sprite_texture(s, &s_i);
		s_i.i--;
	}
}
