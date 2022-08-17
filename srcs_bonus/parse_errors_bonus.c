/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:08:03 by aseptimu          #+#    #+#             */
/*   Updated: 2022/04/13 19:46:08 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "parser_bonus.h"

void	parse_error(char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	parse_std_err(char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	perror(str);
	exit (EXIT_FAILURE);
}

void	parse_lst_fail(char *str, t_list **head)
{
	t_list	*p;

	while (*head)
	{
		p = *head;
		if (p->content)
			free(p->content);
		*head = p->next;
		free(p);
	}
	parse_std_err(str);
	exit (EXIT_FAILURE);
}
