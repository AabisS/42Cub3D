/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:15:09 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/16 18:08:25 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_pos_x(t_storage *s, t_player *p)
{
	if (s->move->left == 1)
	{
		if (s->info->map[(int)(p->pos_y)][(int)(p->pos_x - s->ray->plane_x
		* p->ms)] == '0')
			p->pos_x = p->pos_x - s->ray->plane_x * p->ms;
		if (s->info->map[(int)(p->pos_y - s->ray->plane_y * p->ms)]
		[(int)(p->pos_x)] == '0')
			p->pos_y = p->pos_y - s->ray->plane_y * p->ms;
	}
	if (s->move->right == 1)
	{
		if (s->info->map[(int)(p->pos_y)][(int)(p->pos_x + s->ray->plane_x
		* p->ms)] == '0')
			p->pos_x = p->pos_x + s->ray->plane_x * p->ms;
		if (s->info->map[(int)(p->pos_y + s->ray->plane_y * p->ms)]
		[(int)(p->pos_x)] == '0')
			p->pos_y = p->pos_y + s->ray->plane_y * p->ms;
	}
}

void	player_pos_dir(t_storage *s, t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	if (s->move->turn_left == 1)
	{
		old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-p->rot_s) - p->dir_y * sin(-p->rot_s);
		p->dir_y = old_dir_x * sin(-p->rot_s) + p->dir_y * cos(-p->rot_s);
		old_plane_x = s->ray->plane_y;
		s->ray->plane_y = s->ray->plane_y * cos(p->rot_s) - s->ray->plane_x
		* sin(p->rot_s);
		s->ray->plane_x = old_plane_x * sin(p->rot_s) + s->ray->plane_x
		* cos(p->rot_s);
	}
	if (s->move->turn_right == 1)
	{
		old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(p->rot_s) - p->dir_y * sin(p->rot_s);
		p->dir_y = old_dir_x * sin(p->rot_s) + p->dir_y * cos(p->rot_s);
		old_plane_x = s->ray->plane_y;
		s->ray->plane_y = s->ray->plane_y * cos(-p->rot_s) - s->ray->plane_x
		* sin(-p->rot_s);
		s->ray->plane_x = old_plane_x * sin(-p->rot_s) + s->ray->plane_x
		* cos(-p->rot_s);
	}
}

void	player_pos_cam(t_storage *s, t_player *p)
{
	if (s->move->up == 1)
	{
		if (s->info->map[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x
		* p->ms)] == '0')
			p->pos_x += p->dir_x * p->ms;
		if (s->info->map[(int)(p->pos_y + p->dir_y * p->ms)]
		[(int)(p->pos_x)] == '0')
			p->pos_y += p->dir_y * p->ms;
	}
	if (s->move->down == 1)
	{
		if (s->info->map[(int)(p->pos_y)][(int)(p->pos_x - p->dir_x
		* p->ms)] == '0')
			p->pos_x -= p->dir_x * p->ms;
		if (s->info->map[(int)(p->pos_y - p->dir_y * p->ms)]
		[(int)(p->pos_x)] == '0')
			p->pos_y -= p->dir_y * p->ms;
	}
	player_pos_x(s, p);
	player_pos_dir(s, p);
	if (s->move->sprint == 1)
		p->ms = 0.12;
	if (s->move->sprint == 0)
		p->ms = 0.07;
}
