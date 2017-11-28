/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:32:33 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/28 14:14:55 by mabessir         ###   ########.fr       */
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
			if (ft_isalpha(tetri->tetri[i][j]) == 1)
				map->tab[point->y + i][point->x + j] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void**)&point);
}

t_point	*new_point(int x, int y)
{
	t_point *point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

char	ft_what_alpha(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				return (str[i][j]);
			else
				j++;
		}
		i++;
	}
	return (str[i][j]);
}

int		check_tetrimino(t_map   *map, t_tetri *tetrimino, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetrimino->height)
	{
		j = 0;
		while (j < tetrimino->width)
		{
			if (map->tab[y + i][x + j] != '.' &&
			ft_isalpha(tetrimino->tetri[i][j]) != 1)
				return (0);
			j++;
		}
		i++;
	}
	put_tetriminos(tetrimino, map, new_point(x, y),
	ft_what_alpha(tetrimino->tetri));
	return (1);
}

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
				if (place_all_tetri(tetrimino->next, map) != 0)
					return (1);
				else
					put_tetriminos(tetrimino, map, new_point(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}
