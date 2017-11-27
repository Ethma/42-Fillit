/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:53:10 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/27 14:31:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_poulet(char *buf)
{
	int width;
	int height;
	int x;
	int y;
	int	tmp;

	tmp = 0;
	width = 0;
	height = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (buf[x + y * 5] >= 'A' && buf[x + y * 5] <= 'Z')
				tmp++;
			x++;
		}
		width = width > tmp ? width : tmp;
		tmp = 0;
		y++;
	}
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (buf[x + y * 5] >= 'A' && buf[x + y * 5] <= 'Z')
				tmp++;
			y++;
		}
		height = height > tmp ? height : tmp;
		tmp = 0;
		x++;
	}
	printf("width = %d\n", width);
	printf("height = %d\n", height);
}

int		main(void)
{
	char *buf;

	buf = (char*)malloc(sizeof(buf) * 20);
	buf = "....\n....\n..ZZ\n..ZZ\n";
	ft_poulet(buf);
	return (0);
}
