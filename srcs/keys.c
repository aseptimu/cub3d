/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:23:23 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/13 18:08:21 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_ws(t_cub *cub, double sin_a, double cos_a)
{
	if (cub->keys.s == TRUE)
	{
		if (cub->mapper.map[(int)cub->player.y] \
		[(int)(cub->player.x - cub->player.dir_x * STEP)] == '0')
			cub->player.x += -STEP * cos_a;
		if (cub->mapper.map[(int)(cub->player.y - cub->player.dir_y * STEP)] \
		[(int)cub->player.x] == '0')
			cub->player.y += -STEP * sin_a;
	}
	if (cub->keys.w == TRUE)
	{
		if (cub->mapper.map[(int)cub->player.y] \
		[(int)(cub->player.x + cub->player.dir_x * STEP)] == '0')
			cub->player.x += STEP * cos_a;
		if (cub->mapper.map[(int)(cub->player.y + cub->player.dir_y * STEP)] \
		[(int)cub->player.x] == '0')
			cub->player.y += STEP * sin_a;
	}
}

void	key_ad(t_cub *cub, double sin_a, double cos_a)
{
	if (cub->keys.a == TRUE)
	{
		if (cub->mapper.map[(int)cub->player.y] \
		[(int)(cub->player.x + cub->player.dir_y * STEP)] == '0')
			cub->player.x += STEP * sin_a;
		if (cub->mapper.map[(int)(cub->player.y - cub->player.dir_x * STEP)] \
		[(int)cub->player.x] == '0')
			cub->player.y += -STEP * cos_a;
	}
	if (cub->keys.d == TRUE)
	{
		if (cub->mapper.map[(int)cub->player.y] \
		[(int)(cub->player.x - cub->player.dir_y * STEP)] == '0')
			cub->player.x += -STEP * sin_a;
		if (cub->mapper.map[(int)(cub->player.y + cub->player.dir_x * STEP)] \
		[(int)cub->player.x] == '0')
			cub->player.y += STEP * cos_a;
	}
}

void	key_arrows(t_cub *cub)
{
	double	old_plane;

	if (cub->keys.right == TRUE)
	{
		old_plane = cub->player.plane_x;
		cub->player.plane_x = cub->player.plane_x * \
		cos(ROT) - cub->player.plane_y * sin(ROT);
		cub->player.plane_y = old_plane * sin(ROT) + \
		cub->player.plane_y * cos(ROT);
		cub->player.rotate += ROT;
	}
	if (cub->keys.left == TRUE)
	{
		old_plane = cub->player.plane_x;
		cub->player.plane_x = cub->player.plane_x * \
		cos(-ROT) - cub->player.plane_y * sin(-ROT);
		cub->player.plane_y = old_plane * sin(-ROT) + \
		cub->player.plane_y * cos(-ROT);
		cub->player.rotate -= ROT;
	}
}
