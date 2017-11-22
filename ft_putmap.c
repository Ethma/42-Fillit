/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:40:07 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/22 16:53:25 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/* Initialize a new map with size taken from solver */
char	**ft_create_new_map(int len)
{
	t_map	*map;
	int		x;
	int		y;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = len;
	map->tab = (char **)ft_memalloc(sizeof(char *) * len);
	y = 0;
	while (y < len)
	{
		map->tab[y] = ft_strnew(len);
		x = 0;
		while (x < len)
		{
			map->tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map->tab);
}

/* As the name of the function it permit to print maps */
void	ft_print_map(t_map	*map)
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

/* Free false map */
void	ft_free_map(t_map	*map)
{
	int i;

	i = 0;
	while (i < map->tab[i])
	{
		free(map->tab[i]);
		map->tab[i] = NULL;
		i++;
	}
	free(map->tab);
	map->tab = NULL;
}
