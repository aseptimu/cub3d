/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_doors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:35:59 by wurrigon          #+#    #+#             */
/*   Updated: 2022/04/14 16:36:20 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	handle_key_space(t_cub *cub)
{
	if (cub->mapper.map[(int)cub->player.y] \
	[(int)(cub->player.x + cub->player.dir_x * 1)] == '2')
		cub->mapper.map[(int)cub->player.y] \
	[(int)(cub->player.x + cub->player.dir_x * 1)] = '3';
	else if (cub->mapper.map[(int)(cub->player.y + cub->player.dir_y * 1)] \
	[(int)cub->player.x] == '2')
		cub->mapper.map[(int)(cub->player.y + cub->player.dir_y * 1)] \
	[(int)cub->player.x] = '3';
	cub->keys.space = TRUE;
}

void	handle_key_ctrl(t_cub *cub)
{
	if (cub->mapper.map[(int)cub->player.y] \
	[(int)(cub->player.x + cub->player.dir_x * 1)] == '3' && \
	cub->mapper.map[(int)cub->player.y][(int)cub->player.x] != '3')
		cub->mapper.map[(int)cub->player.y] \
	[(int)(cub->player.x + cub->player.dir_x * 1)] = '2';
	else if (cub->mapper.map[(int)(cub->player.y + cub->player.dir_y * 1)] \
	[(int)cub->player.x] == '3' \
	&& cub->mapper.map[(int)cub->player.y][(int)cub->player.x] != '3')
		cub->mapper.map[(int)(cub->player.y + cub->player.dir_y * 1)] \
	[(int)cub->player.x] = '2';
}
