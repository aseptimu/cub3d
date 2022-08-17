/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:38:12 by wurrigon          #+#    #+#             */
/*   Updated: 2022/04/13 20:13:45 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mouse_move(int x, int y, t_cub *cub)
{
	double	old_plane;

	(void)y;
	if (x > cub->mouse_x)
	{
		old_plane = cub->player.plane_x;
		cub->player.plane_x = cub->player.plane_x \
		* cos(ROT_MOUSE) - cub->player.plane_y * sin(ROT_MOUSE);
		cub->player.plane_y = old_plane * sin(ROT_MOUSE) \
		+ cub->player.plane_y * cos(ROT_MOUSE);
		cub->player.rotate += ROT_MOUSE;
	}
	if (x < cub->mouse_x)
	{
		old_plane = cub->player.plane_x;
		cub->player.plane_x = cub->player.plane_x * \
		cos(-ROT_MOUSE) - cub->player.plane_y * sin(-ROT_MOUSE);
		cub->player.plane_y = old_plane * sin(-ROT_MOUSE) + \
		cub->player.plane_y * cos(-ROT_MOUSE);
		cub->player.rotate -= ROT_MOUSE;
	}
	cub->mouse_x = x;
	return (0);
}
