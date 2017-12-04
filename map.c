/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:17:01 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/01 18:44:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*ft_create_map(int len)
{
	t_map	*map;
	char	**tab;
	int		i;
	int		j;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->size = len;
	i = 0;
	tab = (char**)malloc(sizeof(char*) * len);
	while (i < len)
	{
		tab[i] = ft_strnew(len);
		j = 0;
		while (j < len)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	map->tab = tab;
	return (map);
}

static void	ft_free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->tab[i]));
		i++;
	}
	ft_memdel((void **)&(map->tab));
	ft_memdel((void **)&map);
}

static int	ft_lstlen(t_tetri *head)
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

static int	map_size(int len)
{
	int size;

	size = 2;
	while (size * size < len)
		size++;
	return (size);
}

t_map		*tetri_in_map(t_tetri *head)
{
	t_map	*map;
	int		size;

	size = map_size(ft_lstlen(head) * 4);
	map = ft_create_map(size);
	while ((place_all_tetri(head, map)) == 0)
	{
		size++;
		ft_free_map(map);
		map = ft_create_map(size);
	}
	return (map);
}
