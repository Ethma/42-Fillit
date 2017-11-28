/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:17:01 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/28 13:15:55 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_create_map(int len)
{
	t_map	*map;
	char	**tab;
	int		i;
	int		j;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->size = len;
	i = 0;
	tab = (char **)malloc(sizeof(char **) * len);
	while (i < len)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char *) * len)))
			return (NULL);
		j = 0;
		while (j < len)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	map->tab = tab;
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

void	ft_print_map(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
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
	ft_print_map(map->tab);
}
