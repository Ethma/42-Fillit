/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mendy <Mendy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:25:21 by Mendy             #+#    #+#             */
/*   Updated: 2017/11/27 13:36:44 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../Libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_tetri
{
	char			*tetri;
	struct s_tetri	*next;
	int				height;
	int				width;
}					t_tetri;

typedef struct	s_map
{
	int		size;
	char	*tab;
}				t_map;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

t_tetri	*tetri_parse(char **av);
t_tetri	*ft_lst_tetri(char *buf, t_tetri *head, int tetri_nb);
char	**ft_create_new_map(int len);
void	ft_print_map(t_map	*map);
void	ft_free_map(t_map	*map);
t_point	*new_point(int y, int x);
void	put_tetriminos(t_tetri *tetrimino, t_map *map, t_point *point, char c);
int		check_tetrimino(t_map	*map, t_tetri tetrimino, int x, int y);
int		place_all_tetri(t_tetri *tetrimino, t_map *map);
int		map_size(int len);
t_map	*ft_solve(t_tetri *tetrimino);
int		tetri_parse(char **av);

#endif
