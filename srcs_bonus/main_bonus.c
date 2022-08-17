/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:13:59 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/13 19:45:15 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_cub	cub;
	t_win	win;

	cub = (t_cub){0};
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, WIN_WIDTH, WIN_HEIGHT, "cub");
	win.pix.img = mlx_new_image(win.mlx, WIN_WIDTH, WIN_HEIGHT);
	win.pix.addr = mlx_get_data_addr(win.pix.img, &win.pix.bpp, \
					&win.pix.line_length, &win.pix.endian);
	cub.win = &win;
	parser(argc, argv[1], &cub);
	init_minimap(&cub);
	init_anim(&cub);
	color_ceiling(&cub);
	cub.mouse_x = 0;
	mlx_do_key_autorepeatoff(win.mlx);
	mlx_hook(win.win, 2, 0, &k_press, &cub);
	mlx_hook(win.win, 3, 0, &k_release, &cub);
	mlx_hook(win.win, 17, 0, &ft_close, &cub);
	mlx_hook(win.win, 6, 0, &mouse_move, &cub);
	mlx_loop_hook(win.mlx, &key_hooks, &cub);
	mlx_loop(win.mlx);
	return (0);
}
