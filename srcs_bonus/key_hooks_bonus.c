/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:41:39 by wurrigon          #+#    #+#             */
/*   Updated: 2022/04/14 16:36:11 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	if (key == K_SPACE)
		handle_key_space(cub);
	if (key == K_CTRL)
		handle_key_ctrl(cub);
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
	if (key == K_SPACE)
		cub->keys.space = FALSE;
	return (0);
}

void	draw_animation(t_cub *cub)
{
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, \
	cub->win->pix.img, 0, 0);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, \
	cub->minimap.img, 0, WIN_HEIGHT - MMAP_HEIGH * SCALE);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, \
	cub->anim.anim_imgs[cub->anim.anim / 2], \
	WIN_WIDTH * 0.5 - (cub->anim.anim_x[cub->anim.anim / 2] / 2), \
	WIN_HEIGHT - cub->anim.anim_y[cub->anim.anim / 2]);
	cub->anim.anim++;
	if (cub->anim.anim == 40)
		cub->anim.anim = 0;
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
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, \
	cub->anim.anim_imgs[0], WIN_WIDTH * 0.5 - (cub->anim.anim_x[0] / 2), \
	WIN_HEIGHT - cub->anim.anim_y[0]);
	if (cub->keys.space == TRUE || cub->anim.anim != 0)
		draw_animation(cub);
	if (cub->keys.esc == TRUE)
		ft_close(cub);
	key_ws(cub, sin_a, cos_a);
	key_ad(cub, sin_a, cos_a);
	key_arrows(cub);
	return (0);
}
