/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:44:14 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/27 15:17:50 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include "Libft/libft.h"

void	ft_error(int n)
{
	if (n == 1)
		ft_putstr("error\n");
	if (n == 2)
		ft_putstr("usage: ./fillit source_file\n");
}

int		main(int ac, char **av)
{
	t_tetri	*head;
	t_map	*map;

	head = NULL;
	if (ac == 2)
	{
		if ((head = tetri_parse(&av[1])) == NULL)
			ft_error(1);
	}
	else
		ft_error(2);
	map = ft_solve(head);
	ft_putstr(map->tab);
	return (0);
}
