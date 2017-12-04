/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:32:33 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/01 17:05:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	put_tetriminos(t_tetri *tetri, t_map *map, t_point *point, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->tetri[j][i] == '#')
				map->tab[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void**)&point);
}

t_point		*new_point(int x, int y)
{
	t_point *point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

static int	check_tetrimino(t_map *map, t_tetri *tetrimino, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetrimino->width)
	{
		j = 0;
		while (j < tetrimino->height)
		{
			if (map->tab[y + j][x + i] != '.' && tetrimino->tetri[j][i] == '#')
				return (0);
			j++;
		}
		i++;
	}
	put_tetriminos(tetrimino, map, new_point(x, y), tetrimino->letter);
	return (1);
}

int			place_all_tetri(t_tetri *tetri, t_map *map)
{
	int		x;
	int		y;

	y = 0;
	if (tetri == NULL)
		return (1);
	while (y < (map->size - tetri->height + 1))
	{
		x = 0;
		while (x < (map->size - tetri->width + 1))
		{
			if (check_tetrimino(map, tetri, x, y))
			{
				if (place_all_tetri(tetri->next, map))
					return (1);
				else
					put_tetriminos(tetri, map, new_point(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}
