/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:32:33 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/12 14:16:28 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_cell_floor(char *line, int *floorceil)
{
	int	rgb[3];
	int	i;

	if (*floorceil != -1)
		parse_error("Floor or ceil set several times");
	line++;
	if (*line != ' ')
		parse_error("Need space after ceil/floor id");
	i = 0;
	while (i < 3)
	{
		rgb[i] = ft_atoi_bit(&line);
		if (rgb[i] == -1)
			parse_error("Wrong ceiling/floor color");
		if (*line != ',')
		{
			if (i == 2 && (*line == '\n' || *line == '\0'))
				break ;
			parse_error("Wrong ceiling/floor color");
		}
		line++;
		i++;
	}
	*floorceil = (rgb[0] << 16) | (rgb[1] << 8) | (rgb[2]);
}

static void	import_walls(char *line, t_cub *cub, t_imgs *wall)
{
	int	length;

	length = ft_strlen(line);
	if (length < 4 || ft_strncmp(line + length - 5, ".xpm\n", 5) != 0)
		parse_error("Wrong wall image format. Only .xpm support");
	else
	{
		line[length - 1] = '\0';
		wall->pix.img = mlx_xpm_file_to_image(cub->win->mlx, \
						line, &wall->width, &wall->height);
	}
	if (wall->pix.img == NULL)
		parse_error("Can't take img from .xpm file");
	wall->pix.addr = (unsigned int *)mlx_get_data_addr(wall->pix.img, \
			&wall->pix.bpp, &wall->pix.line_length, &wall->pix.endian);
}

void	get_wall(t_cub *cub, char *line)
{
	int	wall;

	wall = -1;
	if (line[0] == 'N' && line[1] == 'O')
		wall = N_WALL;
	else if (line[0] == 'S' && line[1] == 'O')
		wall = S_WALL;
	else if (line[0] == 'W' && line[1] == 'E')
		wall = W_WALL;
	else if (line[0] == 'E' && line[1] == 'A')
		wall = E_WALL;
	else
		parse_error("Wrong wall id. Use NO/SO/WE/EA");
	if (cub->walls[wall].pix.img)
		parse_error("Duplicate wall id");
	if (line[2] != ' ')
		parse_error("Need space after wall id");
	line += 2;
	while (*line == ' ')
		line++;
	import_walls(line, cub, &cub->walls[wall]);
}
