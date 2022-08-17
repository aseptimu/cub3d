/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:35:54 by wurrigon          #+#    #+#             */
/*   Updated: 2022/04/13 20:12:08 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_ceiling(t_cub *cub)
{
	unsigned int	x;
	unsigned int	y;

	cub->f_c.img = mlx_new_image(cub->win->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cub->f_c.img)
		err("Floor & ceil init error");
	cub->f_c.addr = mlx_get_data_addr(cub->f_c.img, \
	&cub->f_c.bpp, &cub->f_c.line_length, &cub->f_c.endian);
	if (!cub->f_c.addr)
		err("Floor & ceil get address fail");
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(&cub->f_c, x, y, cub->celling_color);
			my_mlx_pixel_put(&cub->f_c, x, WIN_HEIGHT - y - 1,
				cub->floor_color);
			x++;
		}
		y++;
	}
}

static void	imgs_mem_set(t_cub *cub)
{
	ft_memcpy(cub->win->pix.addr, cub->f_c.addr, \
	WIN_HEIGHT * WIN_WIDTH * (cub->win->pix.bpp / 8));
}

void	calc_put_imgs(t_cub *cub)
{
	imgs_mem_set(cub);
	ft_cast_ray2(cub);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, \
	cub->win->pix.img, 0, 0);
}
