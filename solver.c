/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:51:19 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/22 11:41:58 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"fillit.h"

void	ft_solve(t_list	tetri_list)
{
	t_map	*map;
	int		size;

	size = 4;
	map = ft_create_new_map(map);
	while (check_retour_pieces(tetri_list) != 1)
	{
		size++;
		ft_free_map(map);
		map = ft_create_new_map(size);
	}
}
