/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:41:39 by wurrigon          #+#    #+#             */
/*   Updated: 2022/04/13 20:10:35 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	k_press(int key, t_cub *cub)
{
	if (key == K_W)
		cub->keys.w = TRUE;
	if (key == K_A)
		cub->keys.a = TRUE;
	if (key == K_S)
		cub->keys.s = TRUE;
	if (key == K_D)
		cub->keys.d = TRUE;
	if (key == K_LEFT)
		cub->keys.left = TRUE;
	if (key == K_RIGHT)
		cub->keys.right = TRUE;
	if (key == K_ESC)
		cub->keys.esc = TRUE;
	if (key == K_CTRL)
		cub->keys.ctrl = TRUE;
	return (0);
}

int	k_release(int key, t_cub *cub)
{
	if (key == K_W)
		cub->keys.w = FALSE;
	if (key == K_A)
		cub->keys.a = FALSE;
	if (key == K_S)
		cub->keys.s = FALSE;
	if (key == K_D)
		cub->keys.d = FALSE;
	if (key == K_LEFT)
		cub->keys.left = FALSE;
	if (key == K_RIGHT)
		cub->keys.right = FALSE;
	if (key == K_CTRL)
		cub->keys.ctrl = FALSE;
	return (0);
}

int	key_hooks(t_cub *cub)
{
	double	sin_a;
	double	cos_a;

	sin_a = sin(cub->player.rotate);
	cos_a = cos(cub->player.rotate);
	cub->player.dir_x = cos_a;
	cub->player.dir_y = sin_a;
	calc_put_imgs(cub);
	if (cub->keys.esc == TRUE)
		ft_close(cub);
	key_ws(cub, sin_a, cos_a);
	key_ad(cub, sin_a, cos_a);
	key_arrows(cub);
	return (0);
}
