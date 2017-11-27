/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:13:36 by rpinoit           #+#    #+#             */
/*   Updated: 2017/11/23 16:33:24 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char			*ft_tetrin_tab(char *tab, char *buf, int tetri_nb)
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

t_tetri			*ft_lst_tetri(char *buf, t_tetri *head, int tetri_nb)
{
	t_tetri *new;
	t_tetri *lst;

	new = NULL;
	lst = NULL;
	if (tetri_nb == 1)
	{
		head = (t_tetri*)ft_memalloc(sizeof(*head));
		head->tetri = ft_tetrin_tab(head->tetri, buf, tetri_nb);
		head->next = NULL;
	}
	if (tetri_nb > 1)
	{
		lst = head;
		new = (t_tetri*)ft_memalloc(sizeof(*new));
		new->tetri = ft_tetrin_tab(new->tetri, buf, tetri_nb);
		new->next = NULL;
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new;
	}
	return (head);
}

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

static int		tetri_check(char *buf, int max_tetri)
{
	int i;
	int s_max;

	i = 0;
	s_max = 0;
	while (i < 20)
	{
		if (i % 5 == 4 && buf[i] != '\n')
			return (0);
		if (i % 5 < 4 && buf[i] != '.' && buf[i] != '#')
			return (0);
		if (buf[i] == '#')
			s_max++;
		i++;
	}
	max_tetri++;
	if (s_max != 4)
		return (0);
	if (contact_check(buf) == 0)
		return (0);
	return (max_tetri);
}

t_tetri			*tetri_parse(char **av)
{
	int		fd;
	int		tetri_nb;
	int		flag;
	char	buf[20];
	t_tetri	*head;

	flag = 0;
	tetri_nb = 0;
	head = NULL;
	if ((fd = open(*av, O_RDONLY)) == -1)
		return (NULL);
	while (read(fd, (void*)buf, 20) > 0)
	{
		flag = 0;
		if (tetri_nb > 25 || (tetri_nb = tetri_check(buf, tetri_nb)) == 0)
			return (NULL);
		head = ft_lst_tetri(buf, head, tetri_nb);
		if (read(fd, (void*)buf, 1) == 1)
			flag = 1;
		if (flag && buf[0] != '\n')
			return (NULL);
		ft_bzero(buf, 20);
	}
	return (flag == 1 ? NULL : head);
}
