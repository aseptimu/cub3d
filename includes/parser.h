/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:34:48 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/08 14:01:03 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

void	get_cell_floor(char *line, int *floorceil);
void	get_wall(t_cub *cub, char *line);
void	get_map(char *line, int fd, t_cub *cub);

/* utils.c */
int		ft_atoi_bit(char **str);
size_t	get_max(size_t len1, size_t len2);
char	*give_line_back(t_list **lst);

/* parse_errors.c */
void	parse_error(char *str);
void	parse_std_err(char *str);
void	parse_lst_fail(char *str, t_list **head);

#endif