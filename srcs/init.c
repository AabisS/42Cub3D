/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:38:43 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/16 18:08:25 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_struct(t_parse *info)
{
	info->width = 0;
	info->height = 0;
	info->ccolor = 0;
	info->fcolor = 0;
	info->max_len = 0;
	info->max_col = 0;
	info->x = 0;
	info->y = 0;
	info->text_no[0] = '\0';
	info->text_ea[0] = '\0';
	info->text_so[0] = '\0';
	info->text_we[0] = '\0';
	info->text_s[0] = '\0';
	info->player_x = 0;
	info->player_y = 0;
	info->start = 0;
	info->sprite_nbr = 0;
	info->to_save = 0;
	info->rgb_invalid = 0;
	info->err = 0;
}

void	init_struct_move(t_move *move)
{
	move->esc = 0;
	move->up = 0;
	move->down = 0;
	move->left = 0;
	move->right = 0;
	move->turn_left = 0;
	move->turn_right = 0;
	move->sprint = 0;
	move->texture = 1;
}

void	init_struct_player(t_player *player)
{
	player->pos_y = 0;
	player->pos_x = 0;
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->ms = 0.07;
	player->rot_s = 0.05;
}

void	init_pos_player(t_storage *storage, t_player *player)
{
	if (storage->info->start == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	if (storage->info->start == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		storage->ray->plane_x = -0.66;
	}
	if (storage->info->start == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		storage->ray->plane_x = 0;
		storage->ray->plane_y = -0.66;
	}
	if (storage->info->start == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		storage->ray->plane_x = 0;
		storage->ray->plane_y = 0.66;
	}
}

void	init_struct_ray(t_raycasting *ray)
{
	ray->plane_x = 0.66;
	ray->plane_y = 0;
	ray->hit = 0;
}
