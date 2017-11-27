/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:17:01 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/27 19:16:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		map_size(int len)
{
	int size;

	size = 2;
	while (size * size < len)
		size++;
	return (size);
}

int		ft_lstlen(t_tetri *head)
{
	int size;

	size = 0;
	while (head->next != NULL)
	{
		head = head->next;
		size++;
	}
	return (size);
}

void	ft_tetrin_map(t_tetri *head)
{
	t_map	*map;
	int		size;

	size = map_size(ft_lstlen(head) * 4);
	map = ft_create_map(size);
	while ((place_all_tetri(head, map)) == 0)
	{
		free(map->tab);
		map->tab = NULL;
		size++;
		map = ft_create_map(size);
	}
	ft_putstr(map->tab);
}
