/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:05:05 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/14 13:37:34 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include <fcntl.h>
#include "get_next_line.h"

static void	check_input(int argc, char *file)
{
	int		length;

	if (argc != 2)
		parse_error("Wrong number of arguments");
	length = ft_strlen(file);
	if (length < 4 || ft_strncmp(file + length - 4, ".cub", 5) != 0)
		parse_error("Wrong map file (.cub extension required)");
}

static int	check_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\n')
			return (1);
		line++;
	}
	return (0);
}

static void	parse_elements(char **line, int fd, t_cub *cub)
{
	cub->celling_color = -1;
	cub->floor_color = -1;
	*line = get_next_line(fd);
	while (*line)
	{
		if (**line == 'C')
			get_cell_floor(*line, &cub->celling_color);
		else if (**line == 'F')
			get_cell_floor(*line, &cub->floor_color);
		else if (**line == 'W' || **line == 'E' \
				|| **line == 'N' || **line == 'S')
			get_wall(cub, *line);
		else if (check_line(*line) != 0)
			return ;
		free(*line);
		*line = get_next_line(fd);
	}
	parse_error("Map not found or malloc error occur");
}

static void	check_elements(t_cub *cub)
{
	if (cub->celling_color == -1)
		parse_error("Ceil not set");
	if (cub->floor_color == -1)
		parse_error("Floor not set");
	if (cub->walls[N_WALL].pix.img == NULL)
		parse_error("North wall image not set");
	if (cub->walls[S_WALL].pix.img == NULL)
		parse_error("South wall image not set");
	if (cub->walls[W_WALL].pix.img == NULL)
		parse_error("West wall image not set");
	if (cub->walls[E_WALL].pix.img == NULL)
		parse_error("East wall image not set");
	if (cub->walls[DOOR].pix.img == NULL)
		parse_error("Door image not set");
}

void	parser(int argc, char *file, t_cub *cub)
{
	int		fd;
	char	*line;

	line = NULL;
	check_input(argc, file);
	fd = open(file, O_RDWR);
	if (fd == -1)
		parse_std_err("Open file fail");
	parse_elements(&line, fd, cub);
	check_elements(cub);
	get_map(line, fd, cub);
	if (close(fd) == -1)
		parse_std_err("Close file fail");
}
