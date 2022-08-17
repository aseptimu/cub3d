/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:34:48 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/13 19:47:43 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H

# include "cub3d_bonus.h"

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