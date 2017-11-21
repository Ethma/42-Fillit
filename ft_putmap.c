/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:40:07 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/21 16:27:00 by mabessir         ###   ########.fr       */
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

char	**ft_create(int len)
{
	int		i;
	int		j;

	i = 0;
	tab = (char **)malloc(sizeof(char **) * (len + 1));
	if (!tab)
		return (NULL);
	while (i < )
	{
		if (!(tab[i] = (char *)malloc(sizeof(char *) * len)))
			return (NULL);
		j = 0;
		while (j < len)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
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
