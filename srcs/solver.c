/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:32:33 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/27 22:39:40 by Mendy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_tetriminos(t_tetri *tetri, t_map *map, t_point *point, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (ft_isalpha(tetri->tetri[j + i * 5]) == 1)
				map->tab[point->x + j + (point->y + i) * map->size] = c;
				printf("%s", map->tab);
			j++;
		}
		i++;
	}
	ft_memdel((void**)&point);
}

t_point	*new_point(int y, int x)
{
	t_point *point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

int		check_tetrimino(t_map   *map, t_tetri *tetrimino, int x, int y)
{
	int i;
	int j;
	int k;

	k = 64;
	i = 0;
	while (i < tetrimino->height)
	{
		j = 0;
		while (j < tetrimino->width)
		{
			if (map->tab[j + i * 5] != '.' &&
			ft_isalpha(tetrimino->tetri[j + i * 5]) == 1)
				return (0);
			j++;
		}
		i++;
	}
	k++;
	put_tetriminos(tetrimino, map, new_point(y, x), k);
	return (1);
}

int		place_all_tetri(t_tetri *tetrimino, t_map *map)
{
	int x;
	int y;

	y = 0;
	if (tetrimino == NULL)
		return (1);
	while (y < map->size - tetrimino->height)
	{
		x = 0;
		while (x < map->size - tetrimino->width)
		{
			if (check_tetrimino(map, tetrimino, x, y))
			{
				if (place_all_tetri(tetrimino->next, map) != 0)
					return (1);
				else
					put_tetriminos(tetrimino, map, new_point(y, x), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}
