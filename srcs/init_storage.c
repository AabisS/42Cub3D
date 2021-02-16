/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_storage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:19:11 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/16 18:08:25 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_storage(t_parse *info_map, t_minilibx *mlx, t_player *player,
t_storage *storage)
{
	storage->save = 0;
	storage->info = info_map;
	storage->mlx = mlx;
	storage->player = player;
	player->pos_x = storage->info->player_x + 0.5;
	player->pos_y = storage->info->player_y + 0.5;
}

void	fill_storage(t_move *move, t_raycasting *ray, t_storage *storage)
{
	storage->move = move;
	storage->ray = ray;
}
