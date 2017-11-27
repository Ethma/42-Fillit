/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:51:19 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/27 10:40:49 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"fillit.h"

#define I (point->x + j + (point->y + i) * map->size)

void	put_tetriminos(t_tetri *tetrimino, t_map *map, t_point *point, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (ft_isalpha(tetrimino->tetri) == 1)
				map->tab[I] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}
/* Function who test if a piece can be pose */
int		check_tetrimino(t_map	*map, t_tetri tetrimino, int x, int y)
{
	int i;
	int ;

	i = 0;
	while (i < ft_strlen(map->tab))
	{
		x = 0;
		if (map->tab[x] != '.' && ft_isalpha(tetrimino->tetri[x]) != 1)
			return (0);
		x++;
	}
	put_tetriminos()
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
	map = ft_create_new_map(size);
	while (!place_all_tetri(tetrimino, map))
	{
		ft_free_map(map);
		size++;
		map = ft_create_new_map(size);
	}
	return (map)
}
