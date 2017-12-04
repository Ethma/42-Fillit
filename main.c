/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:44:14 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/01 17:13:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_putmap(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->tab[i]);
		ft_putchar('\n');
		i++;
	}
}

static void	ft_error(int n)
{
	if (n == 1)
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
	if (n == 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(EXIT_FAILURE);
	}
}

int			main(int ac, char **av)
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
	map = tetri_in_map(head);
	ft_putmap(map);
	return (0);
}
