/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:14:26 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/14 16:44:15 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"

# define TRUE 	1
# define FALSE 	0

# define N_WALL 0
# define S_WALL 1
# define W_WALL 2
# define E_WALL 3

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define NUM_RAYS	960
# define FOV_K		0.66
# define SCALE		16
# define MMAP_WIDTH	33
# define MMAP_HEIGH	14

# define K_W		13
# define K_A		0
# define K_S		1
# define K_D		2
# define K_RIGHT	124
# define K_LEFT 	123
# define K_ESC 		53
# define K_CTRL 	49

# define STEP		0.05
# define ROT 		0.04
# define ROT_MOUSE 	0.02

# define BROWN		0x000b3d3b
# define DEEP_BLUE	0x00171B69
# define DARK_GREEN 0x00114D19
# define BG_COLOR	0x00000000
# define YELLOW		0x00FFFF00
# define GREEN		0x0000FF00
# define BLUE		0x000000FF
# define FUCHSIA	0x00FF00FF
# define OLIVE		0x00808000
# define TRANSP		0xFF000000

# define FLOOR			0x277fc1
# define CEILING		0xefdc45

typedef struct s_pix_put
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_pix_put;

typedef struct s_imgs
{
	t_pix_put		pix;
	int				width;
	int				height;
}				t_imgs;

typedef struct s_mapper
{
	char			**map;
	unsigned int	length;
	unsigned int	height;
}				t_mapper;

typedef struct s_player
{
	double	x;
	double	y;
	double	rotate;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_keys
{
	char	w;
	char	a;
	char	s;
	char	d;
	char	left;
	char	right;
	char	esc;
	char	space;
	char	ctrl;
}				t_keys;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	t_pix_put	pix;
}				t_win;

typedef struct s_dda
{
	int				x;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
	t_imgs			wall;
	unsigned int	color;
}				t_dda;

typedef struct s_cub
{
	int			floor_color;
	int			celling_color;
	t_pix_put	f_c;
	t_win		*win;
	t_imgs		walls[4];
	t_mapper	mapper;
	t_player	player;
	t_keys		keys;
	t_dda		*dda;
}				t_cub;

/* parser.c */
void	parser(int argc, char *file, t_cub *cub);

/* errors.c */
void	err(char *str);

/* init.c */
void	init(t_cub *cub);

/* utils.c */
void	my_mlx_pixel_put(t_pix_put *data, int x, int y, int color);
int		ft_close(t_cub *cub);

/* color_ceiling.c */
void	color_ceiling(t_cub *cub);
void	calc_put_imgs(t_cub *cub);

/* key_hooks.c */
int		k_press(int key, t_cub *cub);
int		k_release(int key, t_cub *cub);
int		key_hooks(t_cub *cub);

/* ray_cast.c */
void	ft_cast_ray2(t_cub *cub);

/* keys.c */
void	key_ws(t_cub *cub, double sin_a, double cos_a);
void	key_ad(t_cub *cub, double sin_a, double cos_a);
void	key_arrows(t_cub *cub);

/* cubes_drawer.c */
void	calc_dist_size(t_dda *dda);
void	texture_calc(t_cub *cub, t_dda *dda);
void	draw_textures(t_cub *cub, t_dda *dda);

#endif