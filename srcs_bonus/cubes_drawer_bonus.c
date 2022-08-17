/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubes_drawer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:51:42 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/14 11:56:20 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	calc_dist_size(t_dda *dda)
{
	if (dda->side == 0)
		dda->perp_wall_dist = dda->side_dist_x - dda->delta_dist_x;
	else
		dda->perp_wall_dist = dda->side_dist_y - dda->delta_dist_y;
	dda->line_height = (int)WIN_HEIGHT / dda->perp_wall_dist;
	dda->draw_start = -dda->line_height / 2 + WIN_HEIGHT / 2;
	if (dda->draw_start < 0)
		dda->draw_start = 0;
	dda->draw_end = dda->line_height / 2 + WIN_HEIGHT / 2;
	if (dda->draw_end >= WIN_HEIGHT)
		dda->draw_end = WIN_HEIGHT - 1;
}

void	texture_calc(t_cub *cub, t_dda *dda)
{
	if (dda->side == 0)
		dda->wall_x = cub->player.y + dda->perp_wall_dist * dda->ray_dir_y;
	else
		dda->wall_x = cub->player.x + dda->perp_wall_dist * dda->ray_dir_x;
	dda->wall_x -= floor(dda->wall_x);
	dda->tex_x = (int)(dda->wall_x * (double)dda->wall.width);
	if (dda->side == 0 && dda->ray_dir_x > 0)
		dda->tex_x = dda->wall.width - dda->tex_x - 1;
	if (dda->side == 1 && dda->ray_dir_y < 0)
		dda->tex_x = dda->wall.width - dda->tex_x - 1;
	dda->step = 1.0 * dda->wall.height / dda->line_height;
	dda->tex_pos = (dda->draw_start - WIN_HEIGHT / \
	2 + dda->line_height / 2) * dda->step;
}

void	draw_textures(t_cub *cub, t_dda *dda)
{
	while (dda->draw_start < dda->draw_end)
	{
		dda->tex_y = (int)dda->tex_pos & (dda->wall.height - 1);
		dda->tex_pos += dda->step;
		dda->color = *(unsigned int *)(dda->wall.pix.addr + (dda->tex_x * \
		dda->wall.pix.bpp / 8 + dda->tex_y * dda->wall.pix.line_length));
		my_mlx_pixel_put(&cub->win->pix, dda->x * 2, \
			dda->draw_start, dda->color);
		my_mlx_pixel_put(&cub->win->pix, dda->x * 2 + 1, \
			dda->draw_start, dda->color);
		dda->draw_start++;
	}
}
