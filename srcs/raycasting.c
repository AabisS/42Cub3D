/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:14:44 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/16 18:08:25 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calcul_step_init_sidedist(t_raycasting *ray, t_storage *storage)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (storage->player->pos_x - ray->map_x)
		* ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - storage->player->pos_x)
		* ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (storage->player->pos_y - ray->map_y)
		* ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - storage->player->pos_y)
		* ray->deltadist_y;
	}
}

void	ddaalgo(t_raycasting *ray, t_storage *storage, int x)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (storage->info->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->map_x - storage->player->pos_x +
		(1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpwalldist = (ray->map_y - storage->player->pos_y +
		(1 - ray->step_y) / 2) / ray->raydir_y;
	storage->zbuffer[x] = ray->perpwalldist;
}

void	raycaster(t_storage *storage, t_raycasting *ray)
{
	int		x;

	x = 0;
	storage->zbuffer = malloc(sizeof(double) * storage->info->width);
	while (x < storage->info->width)
	{
		ray->cam_x = 2 * x / (double)storage->info->width - 1;
		ray->raydir_x = storage->player->dir_x + ray->plane_x * ray->cam_x;
		ray->raydir_y = storage->player->dir_y + ray->plane_y * ray->cam_x;
		ray->map_x = (int)storage->player->pos_x;
		ray->map_y = (int)storage->player->pos_y;
		ray->deltadist_x = fabs(1 / ray->raydir_x);
		ray->deltadist_y = fabs(1 / ray->raydir_y);
		calcul_step_init_sidedist(ray, storage);
		ddaalgo(ray, storage, x);
		if (storage->move->texture == 0)
			draw_wall_color(storage, ray, x);
		else
			management_texture(storage, ray, x);
		ray->hit = 0;
		x++;
	}
}
