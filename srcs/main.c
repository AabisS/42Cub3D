/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:54:37 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/16 18:08:25 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../cub3d.h"

int	main(int ac, char **av)
{
	int			fd;
	t_parse		info_map;
	t_minilibx	mlx;

	init_struct(&info_map);
	fd = open(av[1], O_RDONLY);
	if (read_files(&info_map, av[1], fd))
		return (0);
	if (ac == 3 && is_same(&info_map, av[2]))
		info_map.to_save = 1;
	else if (ac == 3 && ft_strncmp("--save", av[2], 6) != 0)
		return (0);
	if (!management_program(&info_map, &mlx))
		return (0);
}

int	ft_expose(t_storage *s)
{
	int	i;

	i = 0;
	s->mlx->img = mlx_new_image(s->mlx->ptr, s->info->width, s->info->height);
	s->mlx->data_img = mlx_get_data_addr(s->mlx->img, &s->mlx->bpixel,
	&s->mlx->size_line, &s->mlx->endian);
	s->mlx->bpixel = s->mlx->bpixel / 8;
	while (i < s->info->width * (s->info->height / 2))
		*(int *)&s->mlx->data_img[i++ * s->mlx->bpixel] = s->info->ccolor;
	while (i < s->info->width * (s->info->height))
		*(int *)&s->mlx->data_img[i++ * s->mlx->bpixel] = s->info->fcolor;
	raycaster(s, s->ray);
	management_sprite(s, s->sprite, s->info->sprite_nbr);
	free(s->zbuffer);
	player_pos_cam(s, s->player);
	mlx_put_image_to_window(s->mlx->ptr, s->mlx->win, s->mlx->img, 0, 0);
	if (s->info->to_save == 1)
		write_bmp_file(s);
	mlx_destroy_image(s->mlx->ptr, s->mlx->img);
	if (s->move->esc == 1)
		exit_prog(s);
	return (0);
}

int	management_program(t_parse *map, t_minilibx *mlx)
{
	t_move			move;
	t_player		player;
	t_raycasting	ray;
	t_storage		storage;
	t_texture		texture[6];

	get_pos_sprite(map, &storage);
	init_struct_move(&move);
	init_struct_player(&player);
	init_struct_ray(&ray);
	fill_storage(&move, &ray, &storage);
	init_storage(map, mlx, &player, &storage);
	init_pos_player(&storage, &player);
	if ((mlx->ptr = mlx_init()) == NULL)
		return (error_manage2(10));
	if (!(mlx->win = mlx_new_window(mlx->ptr, map->width,
	map->height, "Cub3d")) || (init_texture(&storage, texture, 64, 64) == 0))
		return (error_manage2(10));
	mlx_hook(mlx->win, 2, 1L << 0, keypress, &move);
	mlx_hook(mlx->win, 3, 1L << 1, keyrelease, &move);
	mlx_hook(mlx->win, 33, 1L << 17, exit_prog, &storage);
	mlx_loop_hook(mlx->ptr, ft_expose, &storage);
	mlx_loop(mlx->ptr);
	return (1);
}
