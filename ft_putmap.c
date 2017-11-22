/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:40:07 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/22 08:47:50 by Mendy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	**ft_map(t_list *lst)
{
	char	**tab;


	while (lst)
	{

		lst->next;
	}
	return ()
}

char	**ft_create_new_map(int len)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = len;
	map->tab = (char **)ft_memalloc(sizeof(char *) * len);
	i = 0;
	while (i < len)
	{
		map->tab[i] = ft_strnew(size);
		j = 0;
		while (j < len)
		{
			map->tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int		main(int ac, char **av)
{
	char	**tab;
	int		i;

	tab = ft_putmap(atoi(av[1]));
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
