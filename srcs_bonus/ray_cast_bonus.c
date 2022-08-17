/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:49:07 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/14 16:45:35 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	dir_dist(t_cub *cub, t_dda *dda)
{
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (cub->player.x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - cub->player.x) * \
							dda->delta_dist_x;
	}
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (cub->player.y - dda->map_y) * \
							dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - cub->player.y) * \
							dda->delta_dist_y;
	}
}

static void	init_rays(t_cub *cub, t_dda *dda)
{
	dda->camera_x = 2 * dda->x / (double) NUM_RAYS - 1;
	dda->ray_dir_x = cub->player.dir_x + cub->player.plane_x * dda->camera_x;
	dda->ray_dir_y = cub->player.dir_y + cub->player.plane_y * dda->camera_x;
	dda->map_x = (int)cub->player.x;
	dda->map_y = (int)cub->player.y;
	dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
	dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
	dda->hit = 0;
	dir_dist(cub, dda);
}

static void	wall_hit(t_cub *cub, t_dda *dda)
{
	dda->hit = 1;
	if (cub->mapper.map[dda->map_y][dda->map_x] == '2')
		dda->wall = cub->walls[DOOR];
	else
	{
		if (dda->side == 0 && dda->ray_dir_x > 0)
			dda->wall = cub->walls[E_WALL];
		else if (dda->side == 0 && dda->ray_dir_x <= 0)
			dda->wall = cub->walls[W_WALL];
		else if (dda->side == 1 && dda->ray_dir_y > 0)
			dda->wall = cub->walls[S_WALL];
		else if (dda->side == 1 && dda->ray_dir_y <= 0)
			dda->wall = cub->walls[N_WALL];
	}
}

static void	dda_alg(t_cub *cub, t_dda *dda)
{
	if (dda->side_dist_x < dda->side_dist_y)
	{
		dda->side_dist_x += dda->delta_dist_x;
		dda->map_x += dda->step_x;
		dda->side = 0;
	}
	else
	{
		dda->side_dist_y += dda->delta_dist_y;
		dda->map_y += dda->step_y;
		dda->side = 1;
	}
	if (cub->mapper.map[dda->map_y][dda->map_x] == '1' || \
	cub->mapper.map[dda->map_y][dda->map_x] == '2')
	{
		wall_hit(cub, dda);
	}
}

void	ft_cast_ray2(t_cub *cub)
{
	t_dda	dda;

	dda.x = 0;
	while (dda.x < NUM_RAYS)
	{
		init_rays(cub, &dda);
		while (dda.hit == 0)
		{
			dda_alg(cub, &dda);
			if (dda.map_x < MMAP_WIDTH && dda.map_y < MMAP_HEIGH)
				my_mlx_pixel_put(&cub->minimap, dda.map_x * SCALE, \
			dda.map_y * SCALE, BLUE);
		}
		calc_dist_size(&dda);
		texture_calc(cub, &dda);
		draw_textures(cub, &dda);
		dda.x++;
	}
	mlx_clear_window(cub->win->mlx, cub->win->win);
}
