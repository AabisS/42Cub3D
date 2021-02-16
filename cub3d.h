/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:13:47 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/16 18:33:36 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "./srcs/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx/mlx.h"

typedef struct		s_parse
{
	int				ccolor;
	int				fcolor;
	int				x;
	int				y;
	int				max_len;
	int				max_col;
	int				width;
	int				height;
	char			**map;
	char			**cpy;
	char			text_no[256];
	char			text_ea[256];
	char			text_so[256];
	char			text_we[256];
	char			text_s[256];
	char			start;
	int				player_x;
	int				player_y;
	int				sprite_nbr;
	char			*save;
	int				to_save;
	int				rgb_invalid;
	int				err;
}					t_parse;

typedef struct		s_raycasting
{
	double			plane_x;
	double			plane_y;
	double			cam_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	int				step_x;
	int				step_y;
	int				hit;
	double			perpwalldist;
	int				side;
}					t_raycasting;

typedef struct		s_move
{
	int				esc;
	int				up;
	int				down;
	int				left;
	int				right;
	int				turn_left;
	int				turn_right;
	int				sprint;
	int				texture;
}					t_move;

typedef struct		s_save
{
	int				fd;
	int				size;
	int				unused;
	int				offset_begin;
	int				header_bytes;
	short int		plane;
	short int		bpixel;
}					t_save;

typedef struct		s_texture
{
	void			*ptr;
	char			*img;
	int				bpixel;
	int				size_line;
	int				endian;
}					t_texture;

typedef struct		s_sprite_info
{
	int				i;
	int				d;
	int				nb;
	double			x;
	double			y;
	double			inv_det;
	double			transformx;
	double			transformy;
	int				screen_x;
	int				height;
	int				drawstart_y;
	int				drawend_y;
	int				width;
	int				drawstart_x;
	int				drawend_x;
	int				texwidth;
	int				texheight;
	int				texx;
	int				texy;
	int				texture;
}					t_sprite_info;

typedef struct		s_minilibx
{
	void			*ptr;
	void			*win;
	char			*img;
	char			*data_img;
	int				bpixel;
	int				size_line;
	int				endian;
}					t_minilibx;

typedef struct		s_text_info
{
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			wallx;
	int				x;
	int				y;
	int				width;
	int				height;
}					t_text_info;

typedef struct		s_player
{
	double			pos_y;
	double			pos_x;
	float			x;
	float			y;
	double			dir_x;
	double			dir_y;
	double			ms;
	double			rot_s;
}					t_player;

typedef struct		s_sprite
{
	double	x;
	double	y;
}					t_sprite;

typedef	struct		s_storage
{
	t_parse			*info;
	t_minilibx		*mlx;
	t_player		*player;
	t_move			*move;
	t_raycasting	*ray;
	t_texture		*texture;
	t_sprite		sprite[50];
	double			*zbuffer;
	int				save;
}					t_storage;

void				draw_south_north(t_storage *storage, int drawstart,
int drawend, int x);
void				draw_wall_color(t_storage *storage,
t_raycasting *ray, int x);
void				init_struct(t_parse *info);
int					fill_resolution(t_parse *info, char *str);
void				fill_path_we(t_parse *info, char *str);
void				fill_path_so(t_parse *info, char *str);
void				fill_path_no(t_parse *info, char *str);
void				fill_path_ea(t_parse *info, char *str);
void				fill_path_sprite(t_parse *info, char *str);
int					down_space(char *str, int i);
int					parse_parameter(char *line, t_parse *info);
int					read_files(t_parse *info_map, char *av, int fd);
char				**malloc_array(int x, int y);
void				print_array(char **tab, int x, int y);
int					exit_prog(t_storage *storage);
int					keypress(int keycode, t_move *move);
int					keyrelease(int keycode, t_move *move);
void				get_pos_sprite(t_parse *info_map, t_storage *storage);
void				init_storage(t_parse *info_map, t_minilibx *mlx,
t_player *player, t_storage *storage);
void				raycaster(t_storage *storage, t_raycasting *ray);
void				fill_storage(t_move *move, t_raycasting *ray,
t_storage *storage);
void				init_struct_ray(t_raycasting *ray);
void				init_struct_move(t_move *move);
void				init_struct_player(t_player *player);
void				init_pos_player(t_storage *storage, t_player *player);
void				player_pos_cam(t_storage *s, t_player *p);
int					management_program(t_parse *map, t_minilibx *mlx);
void				draw_wall_texture_ew(t_storage *s,
t_texture *texture, t_text_info *text_i, int x);
void				draw_wall_texture_sn(t_storage *s,
t_texture *texture, t_text_info *text_i, int x);
void				management_texture(t_storage *s,
t_raycasting *ray, int x);
void				management_sprite(t_storage *s, t_sprite *sprite,
int sprite_nb);
void				init_sprite(t_storage *s, t_sprite *sprite,
int *sprite_order, double *sprite_distance);
void				sort_sprites(int *sprite_order,
double *sprite_distance, int sprite_nb);
void				draw_sprite(t_sprite_info *s_i, t_sprite *sprite,
int *sprite_order, t_storage *s);
void				sprite_texture(t_storage *s, t_sprite_info *s_i);
int					init_texture(t_storage *s, t_texture *texture, int w,
int h);
void				sort_sprites(int *sprite_order, double *sprite_distance,
int sprite_nb);
void				write_bmp_file(t_storage *storage);
void				draw_wall_texture_sn_follow(t_storage *s,
t_texture *texture, t_text_info *text_i, int x);
int					rgb_to_integer(int nb1, int nb2, int nb3);
int					floor_color(t_parse *info, char *str, int c);
int					verif_info(t_parse *info);
int					error_manage(int i);
int					error_manage2(int i);
int					error_manage3(int i);
int					is_same(t_parse *str, char *av);
int					verif_rgb(t_parse *info, int nb1, int nb2, int nb3);
int					maping_parse(int fd, char *line,
t_parse *info_map, char *tmp_map);
int					parse_map(t_parse *info_map);
int					verif_map(t_parse *info, int j);
void				add_nl_to_file(char *av);
int					down_space_reverse(char *str, int i);
void				free_3str(char *s1, char *s2, char *s3);
int					got_space(char *str);
int					map_first_last_line(char *str);

#endif
