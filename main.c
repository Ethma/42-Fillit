/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:44:14 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/21 11:56:30 by rpinoit          ###   ########.fr       */
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
	if (ac == 2)
	{
		if (tetri_parse(&av[1]) == 0)
			ft_error(1);
	}
	else
		ft_error(2);
	return (0);
}
