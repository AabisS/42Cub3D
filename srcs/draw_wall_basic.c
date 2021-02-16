/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:29:35 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/16 18:08:25 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_south_north(t_storage *storage, int drawstart,
int drawend, int x)
{
	if (storage->ray->raydir_y >= 0)
	{
		while (drawstart < drawend)
		{
			*(int *)(&storage->mlx->data_img[((drawstart * storage->
			mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 16724530;
			drawstart++;
		}
	}
	else
	{
		while (drawstart < drawend)
		{
			*(int *)(&storage->mlx->data_img[((drawstart * storage->
			mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 16753920;
			drawstart++;
		}
	}
}

void	draw_east_west(t_storage *storage, int drawstart,
int drawend, int x)
{
	if (storage->ray->raydir_x >= 0)
	{
		while (drawstart < drawend)
		{
			*(int *)(&storage->mlx->data_img[((drawstart * storage->
			mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 3333140;
			drawstart++;
		}
	}
	else
	{
		while (drawstart < drawend)
		{
			*(int *)(&storage->mlx->data_img[((drawstart * storage->
			mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 65535;
			drawstart++;
		}
	}
}

void	draw_wall_color(t_storage *storage, t_raycasting *ray, int x)
{
	int		lineheight;
	int		drawstart;
	int		drawend;

	lineheight = (int)(storage->info->height / ray->perpwalldist);
	lineheight *= 1;
	drawstart = -lineheight / 2 + storage->info->height / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + storage->info->height / 2;
	if (drawend >= storage->info->height)
		drawend = storage->info->height - 1;
	if (ray->side == 1)
		draw_south_north(storage, drawstart, drawend, x);
	else
		draw_east_west(storage, drawstart, drawend, x);
}
