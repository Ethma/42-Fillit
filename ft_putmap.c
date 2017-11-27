/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:40:07 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/27 15:04:15 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "includes/fillit.h"

/* Initialize a new map with size taken from solver */
t_map	*ft_create_map(int len)
{
	t_map	*map;
	int		x;
	int		y;
	int		i;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->size = len;
	map->tab = (char*)ft_memalloc(sizeof(map->tab) * len + 1);
	y = 0;
	while (y < len)
	{
		x = 0;
		while (x <= len)
		{
			i = x + y * (len + 1);
			(x / len == 0) ? (map->tab[i] = '.') : (map->tab[i] = '\n');
			x++;
		}
		y++;
	}
	return (map);
}
/* Free false map */
void	ft_free_map(t_map *map)
{
	free(map->tab);
	map->tab = NULL;
}
/* Function who calculates the number of tetriminos given */
int		ft_lstlen(t_tetri *head)
{
	int	size;

	size = 0;
	while (head->next != NULL)
	{
		head = head->next;
		size++;
	}
	return (size);
}
/* Calculate the map min size */
int		map_size(int len)
{
	int size;

	size = 2;
	while (size * size < len)
		size++;
	return (size);
}

/* Add a new struct point */
t_point		*new_point(int y, int x)
{
	t_point		*point;

	point = (t_point)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}
