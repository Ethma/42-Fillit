/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:44:14 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/27 17:45:14 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(int n)
{
	if (n == 1)
		ft_putstr("error\n");
	if (n == 2)
		ft_putstr("usage: ./fillit source_file\n");
}

int		main(int ac, char **av)
{
	t_tetri *head;

	head = NULL;
	if (ac == 2)
	{
		if ((head = tetri_parse(&av[1])) == NULL)
			ft_error(1);
		ft_tetrin_map(head);
	}
	else
		ft_error(2);
	return (0);
}
