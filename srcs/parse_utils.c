/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:04:40 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/05 22:55:24 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
