/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:18:01 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/16 18:08:25 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int					keyrelease(int keycode, t_move *move)
{
	if (keycode == 65307)
		move->esc = 0;
	else if (keycode == 119)
		move->up = 0;
	else if (keycode == 115)
		move->down = 0;
	else if (keycode == 97)
		move->left = 0;
	else if (keycode == 100)
		move->right = 0;
	else if (keycode == 65361)
		move->turn_left = 0;
	else if (keycode == 65363)
		move->turn_right = 0;
	return (0);
}

int					keypress(int keycode, t_move *move)
{
	if (keycode == 65307)
		move->esc = 1;
	else if (keycode == 119)
		move->up = 1;
	else if (keycode == 115)
		move->down = 1;
	else if (keycode == 97)
		move->left = 1;
	else if (keycode == 100)
		move->right = 1;
	else if (keycode == 65361)
		move->turn_left = 1;
	else if (keycode == 65363)
		move->turn_right = 1;
	return (0);
}
