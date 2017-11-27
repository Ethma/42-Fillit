/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:16:34 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/27 18:46:59 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*ft_tetri_pos(t_tetri *lst)
{
	t_pos	*pos;
	int		x;
	int		y;

	pos = (t_pos*)ft_memalloc(sizeof(*pos));
	y = 0;
	pos->min_x = 5;
	pos->max_x = 0;
	pos->min_y = 5;
	pos->max_y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (lst->tetri[x + y * 5] >= 'A' && lst->tetri[x + y * 5] <= 'Z')
			{
				pos->max_x = x > pos->max_x ? x : pos->max_x;
				pos->max_y = y > pos->max_y ? y : pos->max_y;
				pos->min_x = x < pos->min_x ? x : pos->min_x;
				pos->min_y = y < pos->min_y ? y : pos->min_y;
			}
			x++;
		}
		y++;
	}
	lst->width = pos->max_x - pos->min_x + 1;
	lst->height = pos->max_y - pos->min_y + 1;
	return (lst);
}

char		*ft_tetrin_tab(char *tab, char *buf, int tetri_nb)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
		i++;
	tab = (char*)ft_memalloc(sizeof(*tab) * (i + 1));
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
			tab[i] = tetri_nb + '@';
		else
			tab[i] = buf[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

t_tetri		*ft_lst_tetri(char *buf, t_tetri *head, int tetri_nb)
{
	t_tetri *new;
	t_tetri *lst;

	new = NULL;
	lst = NULL;
	if (tetri_nb == 1)
	{
		head = (t_tetri*)ft_memalloc(sizeof(*head));
		head->tetri = ft_tetrin_tab(head->tetri, buf, tetri_nb);
		head = ft_tetri_pos(head);
		head->next = NULL;
	}
	if (tetri_nb > 1)
	{
		lst = head;
		new = (t_tetri*)ft_memalloc(sizeof(*new));
		new->tetri = ft_tetrin_tab(new->tetri, buf, tetri_nb);
		new = ft_tetri_pos(new);
		new->next = NULL;
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new;
	}
	return (head);
}
