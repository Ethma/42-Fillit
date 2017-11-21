/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:09:44 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/21 13:12:00 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		contact_check(char *buf)
{
	int i;
	int contact;

	i = 0;
	contact = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#')
				contact++;
			if (buf[i - 1] == '#')
				contact++;
			if (buf[i + 5] == '#')
				contact++;
			if (buf[i - 5] == '#')
				contact++;
		}
		i++;
	}
	if (contact == 6 || contact == 8)
		return (1);
	return (0);
}

static int		tetri_check(char *buf)
{
	int i;
	int t_max;

	i = 0;
	t_max = 0;
	while (i < 20)
	{
		if (i % 5 == 4 && buf[i] != '\n')
			return (0);
		if (i % 5 < 4 && buf[i] != '.' && buf[i] != '#')
			return (0);
		if (buf[i] == '#')
			t_max++;
		i++;
	}
	if (t_max != 4)
		return (0);
	if (contact_check(buf) == 0)
		return (0);
	return (1);
}

int				tetri_parse(char **av)
{
	int		fd;
	int		flag;
	int		max_tetri;
	char	buf[20];

	flag = 0;
	max_tetri = 0;
	if ((fd = open(*av, O_RDONLY)) == -1)
		return (0);
	while (read(fd, (void*)buf, 20) > 0)
	{
		flag = 0;
		max_tetri++;
		if (max_tetri > 26 || tetri_check(buf) == 0)
			return (0);
		if (read(fd, (void*)buf, 1) == 1)
			flag = 1;
		if (flag && buf[0] != '\n')
			return (0);
		ft_bzero(buf, 20);
	}
	if (flag)
		return (0);
	return (1);
}
