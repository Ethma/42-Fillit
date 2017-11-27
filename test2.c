/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:31:45 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/27 18:31:17 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void    ft_poulet(char *buf)
{
	int min_x;
	int max_x;
	int min_y;
	int max_y;
	int x;
	int y;
	int width;
	int height;

	min_x = 5;
	max_x = 0;
	min_x = 5;
	max_y = 0;
	x = -1;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (buf[x + y * 5] >= 'A' && buf[x + y * 5] <= 'Z')
			{
				max_x = x > max_x ? x : max_x;
				max_y = y > max_y ? y : max_y;
				min_x = x < min_x ? x : min_x;
				min_y = y < min_y ? y : min_y;
			}
		}
	}
	width = max_x - min_x + 1;
	height = max_y - min_y + 1;
	printf("width = %d\n", width);
	printf("height = %d\n", height);
}

int     main(void)
{
	char *buf;

	buf = (char*)malloc(sizeof(buf) * 20);
	buf = "..ZZ\n.ZZ.\n....\n....\n";
	ft_poulet(buf);
	return (0);
}
