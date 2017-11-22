/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mendy <Mendy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:25:21 by Mendy             #+#    #+#             */
/*   Updated: 2017/11/22 15:58:10 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "Libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

int		tetri_parse(char **av);

typedef struct		s_tetri
{
	char			**tetri;
	struct s_tetri	*next;
}					t_tetri;

typedef struct	s_map
{
	int		size;
	char	**tab;
}				t_map;

#endif
