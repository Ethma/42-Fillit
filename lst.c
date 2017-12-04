/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:16:34 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/01 18:50:30 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tetri_select(char **tab, t_tetri *lst, t_pos *pos)
{
	char	**str;
	int		i;
	int		j;
	int		x;

	i = -1;
	str = (char**)malloc(sizeof(str) * (lst->width + 1));
	while ((pos->min_y + ++i) <= pos->max_y)
	{
		x = pos->min_x;
		j = -1;
		str[i] = (char*)malloc(sizeof(str[i]) * (lst->height + 1));
		while ((x + j++) <= pos->max_x)
			str[i][j] = tab[pos->min_y + i][x + j];
		str[i][j] = '\0';
	}
	str[i] = NULL;
	if (lst->height == 4)
	{
		str[0][0] = '#';
		str[0][1] = '\0';
		str[2][0] = '#';
		str[2][1] = '\0';
	}
	return (str);
}

t_pos	*ft_tetri_pos(char *buf, t_pos *pos)
{
	int	x;
	int	y;

	pos = (t_pos*)ft_memalloc(sizeof(*pos));
	y = -1;
	pos->min_x = 5;
	pos->max_x = 0;
	pos->min_y = 5;
	pos->max_y = 0;
	while (y++ < 4)
	{
		x = -1;
		while (x++ < 4)
		{
			if (buf[x + y * 5] == '#')
			{
				pos->max_x = x > pos->max_x ? x : pos->max_x;
				pos->max_y = y > pos->max_y ? y : pos->max_y;
				pos->min_x = x < pos->min_x ? x : pos->min_x;
				pos->min_y = y < pos->min_y ? y : pos->min_y;
			}
		}
	}
	return (pos);
}

t_tetri	*ft_tetri_in_tab(t_tetri *lst, char *buf, int tetri_nb, t_pos *pos)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	tab = (char**)ft_memalloc(sizeof(tab) * 5);
	while (i < 4)
	{
		tab[i] = (char*)malloc(sizeof(char) * 5);
		j = 0;
		while (j < 4)
		{
			if (buf[j + i * 5] == '#')
				tab[i][j] = '#';
			else
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
	lst->letter = tetri_nb + '@';
	lst->width = pos->max_x - pos->min_x + 1;
	lst->height = pos->max_y - pos->min_y + 1;
	lst->tetri = ft_tetri_select(tab, lst, pos);
	return (lst);
}

t_tetri	*ft_lst_tetri(char *buf, t_tetri *head, int tetri_nb)
{
	t_tetri	*new;
	t_pos	*pos;
	t_tetri	*lst;

	new = NULL;
	pos = NULL;
	lst = head;
	if (tetri_nb == 1)
	{
		head = (t_tetri*)ft_memalloc(sizeof(*head));
		pos = ft_tetri_pos(buf, pos);
		head = ft_tetri_in_tab(head, buf, tetri_nb, pos);
		head->next = NULL;
	}
	if (tetri_nb > 1)
	{
		new = (t_tetri*)ft_memalloc(sizeof(*new));
		pos = ft_tetri_pos(buf, pos);
		new = ft_tetri_in_tab(new, buf, tetri_nb, pos);
		new->next = NULL;
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new;
	}
	return (head);
}
