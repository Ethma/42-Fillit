/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:40:03 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/21 13:41:03 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *lst)
{
	int i;

	i = 0;
	if (lst == NULL)
		return ;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
