/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:04:40 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/13 19:45:45 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

size_t	get_max(size_t len1, size_t len2)
{
	if (len1 > len2)
		return (len1);
	else
		return (len2);
}

int	ft_atoi_bit(char **str)
{
	int	num;

	while (**str == ' ')
		(*str)++;
	if (ft_isdigit(**str) == 0)
		return (-1);
	num = 0;
	while (ft_isdigit(**str))
	{
		num = num * 10 + **str - '0';
		if (num > 255)
			return (-1);
		(*str)++;
	}
	while (**str == ' ')
		(*str)++;
	return (num);
}

char	*give_line_back(t_list **lst)
{
	t_list	*tmp;
	char	*ret;

	tmp = *lst;
	ret = (char *)tmp->content;
	*lst = (*lst)->next;
	free(tmp);
	return (ret);
}
