/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:51:19 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/23 12:17:33 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"fillit.h"



int		put_tetriminos()

/* Function who test if a piece can be pose */
int		check_tetrimino(t_map	*map, int x, int y)
{
	int i;
	int j;

	while (tetrimino->tetri[i] == '.' || tetrimino->tetri[i] == '\n')
		i++;
	if (map->tab[i][j] == '.')
	{
		map->tab[i][j] == tetrimino->tetri[i];
		j++;
	}
	else if (map[i][j] == '\0')
		i++;
	else
		j++;
	return (1);
}

/*  Backtracking function */
int		place_all_tetri(t_tetri *tetrimino, t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (check_tetrimino(map, tetrimino, x, y) != 0)
			{
				put_tetriminos();    bnm
				if (place_all_tetri(tetrimino->next, map) != 1)
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int		map_size(int len)
{
	size = 2;
	while (size * size < len)
		size++;
	return (size);
}

t_map	*ft_solve(t_tetri tetrimino)
{
	t_map	*map;
	int		size;

	size = map_size(ft_lstlen(tetrimino) * 4);
	map = ft_create_new_map(map);
	while (place_all_tetri(tetrimino, map) != 1)
	{
		ft_free_map(map);
		size++;
		map = ft_create_new_map(size);
	}
	return (map)
}
