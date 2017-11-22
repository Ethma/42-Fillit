/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:51:19 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/22 17:03:07 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"fillit.h"

int		map_size(int len)
{
	size = 2;
	while (size * size < len)
		size++;
	return (size);
}

int		put_tetriminos(t_tetri	*tetrimino, t_map	*map)
{
	int y;
	int x;
	int i;

	y = 0;
	x = 0;
	i = 0;
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
int		check_return_pieces(t_tetri	*tetrimino)
{
	while (tetrimino)
	{
		if (put_tetriminos(tetrimino) == NULL)
			return (0);
		tetrimino->next;
	}
	return (1);
}

t_map	*ft_solve(t_tetri	*tetrimino)
{
	t_map	*map;
	int		size;
	int		i;

	i = 0;
	size = map_size(ft_lstlen(tetrimino) * 4);
	map = ft_create_new_map(map);
	while (i < ft_lstlen(tetrimino))
	{
		check_return_pieces(tetrimino);
		ft_free_map(map);
		size++;
		map = ft_create_new_map(size);
		i++;
	}
	return (map)
}
