/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:23:23 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/14 14:59:35 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	key_ws(t_cub *cub, double sin_a, double cos_a)
{
	char	tmp1;
	char	tmp2;

	if (cub->keys.s == TRUE)
	{
		tmp1 = cub->mapper.map[(int)cub->player.y] \
		[(int)(cub->player.x - cub->player.dir_x * STEP)];
		tmp2 = cub->mapper.map[(int)(cub->player.y - cub->player.dir_y * STEP)] \
		[(int)cub->player.x];
		if (tmp1 == '0' || tmp1 == '3')
			cub->player.x += -STEP * cos_a;
		if (tmp2 == '0' || tmp2 == '3')
			cub->player.y += -STEP * sin_a;
	}
	if (cub->keys.w == TRUE)
	{
		tmp1 = cub->mapper.map[(int)cub->player.y] \
		[(int)(cub->player.x + cub->player.dir_x * STEP)];
		tmp2 = cub->mapper.map[(int)(cub->player.y + cub->player.dir_y * STEP)] \
		[(int)cub->player.x];
		if (tmp1 == '0' || tmp1 == '3')
			cub->player.x += STEP * cos_a;
		if (tmp2 == '0' || tmp2 == '3')
			cub->player.y += STEP * sin_a;
	}
}

void	key_ad(t_cub *cub, double sin_a, double cos_a)
{
	char	tmp1;
	char	tmp2;

	if (cub->keys.a == TRUE)
	{
		tmp1 = cub->mapper.map[(int)cub->player.y] \
		[(int)(cub->player.x + cub->player.dir_y * STEP)];
		tmp2 = cub->mapper.map[(int)(cub->player.y - cub->player.dir_x * STEP)] \
		[(int)cub->player.x];
		if (tmp1 == '0' || tmp1 == '3')
			cub->player.x += STEP * sin_a;
		if (tmp2 == '0' || tmp2 == '3')
			cub->player.y += -STEP * cos_a;
	}
	if (cub->keys.d == TRUE)
	{
		tmp1 = cub->mapper.map[(int)cub->player.y] \
		[(int)(cub->player.x - cub->player.dir_y * STEP)];
		tmp2 = cub->mapper.map[(int)(cub->player.y + cub->player.dir_x * STEP)] \
		[(int)cub->player.x];
		if (tmp1 == '0' || tmp1 == '3')
			cub->player.x += -STEP * sin_a;
		if (tmp2 == '0' || tmp2 == '3')
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
