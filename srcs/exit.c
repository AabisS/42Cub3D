/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:23:42 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/16 18:08:25 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	exit_prog(t_storage *storage)
{
	int		y;

	y = 0;
	while (storage->info->map[y])
	{
		free(storage->info->map[y]);
		y++;
	}
	free(storage->info->map[y]);
	free(storage->info->map);
	mlx_clear_window(storage->mlx->ptr, storage->mlx->win);
	mlx_destroy_window(storage->mlx->ptr, storage->mlx->win);
	exit(0);
	return (1);
}
