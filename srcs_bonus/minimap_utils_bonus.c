/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:19:12 by wurrigon          #+#    #+#             */
/*   Updated: 2022/04/13 19:45:21 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_minimap_copy(t_cub *cub)
{
	int	x;
	int	y;

	cub->minimap_cpy.img = mlx_new_image(cub->win->mlx, MMAP_WIDTH \
	* SCALE, MMAP_HEIGH * SCALE);
	if (!cub->minimap_cpy.img)
		err("Minimap copy img create fail");
	cub->minimap_cpy.addr = mlx_get_data_addr(cub->minimap_cpy.img, \
	&cub->minimap_cpy.bpp, &cub->minimap_cpy.line_length, \
	&cub->minimap_cpy.endian);
	if (!cub->minimap_cpy.addr)
		err("Minimap copy get address fail");
	y = 0;
	while (y < MMAP_HEIGH * SCALE)
	{
		x = 0;
		while (x < MMAP_WIDTH * SCALE)
		{
			my_mlx_pixel_put(&cub->minimap_cpy, x, y, TRANSP);
			x++;
		}
		y++;
	}
}
