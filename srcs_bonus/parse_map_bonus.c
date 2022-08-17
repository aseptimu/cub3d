/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:05:14 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/14 12:10:50 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "get_next_line.h"

static void	check_get_char(t_cub *cub, unsigned int y, unsigned int x)
{
	const char	*dir = "ESWN";

	if (!ft_strchr(" 210NSWE", cub->mapper.map[y][x]))
		parse_error("Wrong symbols on map. Use' 210NSWE'");
	else if (cub->mapper.map[y][x] == ' ' || cub->mapper.map[y][x] == '1')
		return ;
	else if (x == 0 || x == cub->mapper.length - 1 \
			|| y == 0 || y == cub->mapper.height - 1)
		parse_error("Map must be surrounded by walls");
	else if (cub->mapper.map[y - 1][x] == ' ' || cub->mapper.map[y + 1][x] == \
	' ' || cub->mapper.map[y][x + 1] == ' ' || cub->mapper.map[y][x - 1] == ' ')
		parse_error("Map must be surrounded by walls");
	else if (ft_strchr("NSWE", cub->mapper.map[y][x]))
	{
		if (cub->player.x != 0 && cub->player.y != 0)
			parse_error("Only one starting position is allowed");
		cub->player = (t_player){x + 0.5, y + 0.5, 0, 0, 0, 0, 0};
		cub->player.rotate = M_PI_2 * \
		(ft_strchr(dir, cub->mapper.map[y][x]) - dir);
		cub->player.dir_x = cos(cub->player.rotate);
		cub->player.dir_y = sin(cub->player.rotate);
		cub->player.plane_x = -FOV_K * (int)cub->player.dir_y;
		cub->player.plane_y = FOV_K * (int)cub->player.dir_x;
		cub->mapper.map[y][x] = '0';
	}
}

static void	builder(t_cub *cub)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < cub->mapper.height)
	{
		x = 0;
		while (x < cub->mapper.length - 1)
		{
			check_get_char(cub, y, x);
			x++;
		}
		y++;
	}
}

static void	build_map(t_cub *cub, t_list *head)
{
	unsigned int	i;
	char			*line;
	int				len;

	i = 0;
	cub->mapper.map = (char **)malloc(sizeof(char *) * cub->mapper.height);
	if (!cub->mapper.map)
		parse_std_err("Malloc error");
	while (i < cub->mapper.height)
	{
		cub->mapper.map[i] = (char *)malloc(sizeof(char) * cub->mapper.length);
		if (!cub->mapper.map[i])
			parse_std_err("Malloc error");
		line = give_line_back(&head);
		len = ft_strlen(line);
		ft_memcpy(cub->mapper.map[i], line, len - 1);
		ft_memset(cub->mapper.map[i] + (len - 1), ' ', \
				cub->mapper.length - len);
		cub->mapper.map[i][cub->mapper.length - 1] = '\0';
		free(line);
		i++;
	}
	builder(cub);
	if (cub->player.x == 0 && cub->player.y == 0)
		parse_error("Player position not set");
}

static void	line_taker(char **line, int fd, t_cub *cub, t_list **head)
{
	t_list	*lst;
	size_t	len;
	char	*tmp;

	lst = ft_lstnew(*line);
	if (lst == NULL)
		parse_std_err("Malloc error");
	ft_lstadd_back(head, lst);
	len = ft_strlen(*line);
	if ((*line)[len - 1] != '\n')
	{
		tmp = *line;
		*line = ft_strjoin(*line, "\n");
		if (!*line)
			parse_error("Malloc error");
		free(tmp);
	}
	cub->mapper.length = get_max(len, cub->mapper.length);
	cub->mapper.height++;
	*line = get_next_line(fd);
}

void	get_map(char *line, int fd, t_cub *cub)
{
	t_list	*head;

	head = ft_lstnew(line);
	if (head == NULL)
		parse_std_err("Malloc error");
	cub->mapper.length = ft_strlen(line);
	cub->mapper.height = 1;
	line = get_next_line(fd);
	while (line && *line != '\n')
		line_taker(&line, fd, cub, &head);
	if (line && *line == '\n')
		parse_error("Empty lines on map forbidden");
	free(line);
	build_map(cub, head);
}
