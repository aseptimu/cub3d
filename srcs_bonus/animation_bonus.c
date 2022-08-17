/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:13:32 by wurrigon          #+#    #+#             */
/*   Updated: 2022/04/13 19:44:49 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_anim2(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		cub->anim.anim_imgs[i] = mlx_xpm_file_to_image(cub->win->mlx, \
		cub->anim.anim_names[i], &cub->anim.anim_x[i], &cub->anim.anim_y[i]);
		if (!cub->anim.anim_imgs[i])
			err("Loading weapon img fail");
		i++;
	}
}

void	init_anim(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		ft_strlcpy(cub->anim.anim_names[i], "./assets/animation/00.xpm", 26);
		if (i < 10)
			cub->anim.anim_names[i][20] = '0' + i;
		else
		{
			cub->anim.anim_names[i][19] = 1 + '0';
			cub->anim.anim_names[i][20] = '0' + i - 10;
		}
		i++;
	}
	init_anim2(cub);
}
