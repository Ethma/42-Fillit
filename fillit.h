/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:26:56 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/01 19:00:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "Libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_tetri
{
	char			letter;
	int				height;
	int				width;
	char			**tetri;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_map
{
	int				x;
	int				y;
	int				size;
	char			**tab;
}					t_map;

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_pos
{
	int				min_x;
	int				max_x;
	int				min_y;
	int				max_y;
}					t_pos;

int					place_all_tetri(t_tetri *tetrimino, t_map *map);
t_map				*tetri_in_map(t_tetri *head);
t_tetri				*tetri_parse(char **av);
t_tetri				*ft_lst_tetri(char *buf, t_tetri *head, int tetri_nb);

#endif
