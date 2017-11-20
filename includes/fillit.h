/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mendy <Mendy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:25:21 by Mendy             #+#    #+#             */
/*   Updated: 2017/11/20 23:33:40 by Mendy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct	s_map
{
	int		size;
	char	**tab;
}				t_map;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

#endif
