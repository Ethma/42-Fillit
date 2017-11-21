/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mendy <Mendy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:35:02 by Mendy             #+#    #+#             */
/*   Updated: 2017/11/21 09:43:55 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fillit.h"

t_map		ft_initialize_map(int len)
{
	int 	i;
	int 	j;
	t_map	*map;

	if(!(map =(t_map *)malloc(sizeof(t_map) * (len))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

t_map		ft_reinitialize(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->next)
	{
		map[i][j] =
	}
}
