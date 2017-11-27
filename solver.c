/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:51:19 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/27 14:34:49 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Libft/libft.h"
#include	"includes/fillit.h"

void	put_tetriminos(t_tetri *tetrimino, t_map *map, t_point *point, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetrimino->width)
	{
		j = 0;
		while (j < tetrimino->height)
		{
			if (ft_isalpha(tetrimino->tetri[j + i * 5]) == 1)
				map->tab[point->x + j + (point->y + i) * map->size] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}
/* Function who test if a piece can be pose */
int		check_tetrimino(t_map	*map, t_tetri *tetrimino, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetrimino->height)
	{
		j = 0;
		while (j < tetrimino->width)
		{
			if (map->tab[j + i * 5] != '.' && ft_isalpha(tetrimino->tetri
				[j + i * 5]) != 1)
				return (0);
			j++;
		}
		i++;
	}
	put_tetriminos(tetrimino, map, new_point(x, y), tetrimino->tetri
	[point->x + j + (point y + i) * map->size]);
	return (1);
}

/*  Backtracking function */
int		place_all_tetri(t_tetri *tetrimino, t_map *map)
{
	int x;
	int y;

	y = 0;
	if (tetrimino == NULL)
		return (1);
	while (y <= (map->size - tetrimino->height))
	{
		x = 0;
		while (x <= (map->size - tetrimino->width))
		{
			if (check_tetrimino(map, tetrimino, x, y) != 0)
			{
				if (place_all_tetri(tetrimino->next, map))
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

int		map_size(int len)
{
	int size;

	size = 2;
	while (size * size < len)
		size++;
	return (size);
}

t_map	*ft_solve(t_tetri *tetrimino)
{
	t_map	*map;
	int		size;

	size = map_size(ft_lstlen(tetrimino) * 4);
	map->tab = ft_create_new_map(size);
	while (!place_all_tetri(tetrimino, map))
	{
		ft_free_map(map->tab);
		size++;
		map->tab = ft_create_new_map(size);
	}
	return (map);
}
