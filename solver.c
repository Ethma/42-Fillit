/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:51:19 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/22 13:31:44 by mabessir         ###   ########.fr       */
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
	while (tetrimino->tetri[y][x] == '.' || tetrimino->tetri[y][x] == '\n')
		i++;
	if (tetrimino->tetri[y][x] =)
	{
	}
	return (1);
}
int		check_retour_pieces(t_tetri	*tetrimino)
{
	while (tetrimino)
	{
		if (put_tetriminos(tetrimino) == 0)
			return (0);
		tetrimino->next;
	}
	return (1);
}

t_map	*ft_solve(t_tetri	*tetrimino)
{
	t_map	*map;
	int		size;

	size = map_size(ft_lstlen(tetrimino) * 4);
	map = ft_create_new_map(map);
	while (check_retour_pieces(tetrimino) != 1)
	{
		size++;
		ft_free_map(map);
		map = ft_create_new_map(size);
	}
	return (map)
}
