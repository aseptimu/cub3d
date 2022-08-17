/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:14:18 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/13 19:45:18 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_minimap(t_cub *cub)
{
	cub->minimap.img = mlx_new_image(cub->win->mlx, MMAP_WIDTH \
	* SCALE, MMAP_HEIGH * SCALE);
	if (!cub->minimap.img)
		err("Minimap init error");
	cub->minimap.addr = mlx_get_data_addr(cub->minimap.img, &cub->minimap.bpp, \
						&cub->minimap.line_length, &cub->minimap.endian);
	if (!cub->minimap.addr)
		err("Minimap get address fail");
	init_minimap_copy(cub);
}

void	drawer(t_cub *cub, double x, double y, int color)
{
	unsigned int	i;
	unsigned int	j;

	i = y * SCALE;
	while (i < y * SCALE + SCALE)
	{
		j = x * SCALE;
		while (j < x * SCALE + SCALE)
		{
			my_mlx_pixel_put(&cub->minimap, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_pix_put img, t_player *draw, int radius, int color)
{
	int	x;
	int	y;

	x = (draw->x * SCALE) - radius;
	while (x <= draw->x * SCALE + (radius))
	{
		y = draw->y * SCALE - radius;
		while (y <= draw->y * SCALE + (radius))
		{
			if ((x - draw->x * SCALE) * (x - draw->x * SCALE) + \
			(y - draw ->y * SCALE) * (y - draw->y * SCALE) <= radius * radius)
			{
				if (x / SCALE < MMAP_WIDTH && y / SCALE < MMAP_HEIGH)
					my_mlx_pixel_put(&img, x, y, color);
			}	
			y++;
		}
		x++;
	}
}

static void	draw_minimap_walls(t_cub *cub)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < cub->mapper.height)
	{
		x = 0;
		while (x < cub->mapper.length)
		{
			if (cub->mapper.map[y][x] == '1')
			{
				if (x < MMAP_WIDTH && y < MMAP_HEIGH)
					drawer(cub, x, y, BROWN);
			}
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_cub *cub)
{
	draw_minimap_walls(cub);
	draw_circle(cub->minimap, &cub->player, 5, FUCHSIA);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, \
		cub->minimap.img, 0, WIN_HEIGHT - MMAP_HEIGH * SCALE);
}
