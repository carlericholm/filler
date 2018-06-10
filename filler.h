/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 10:51:02 by cholm             #+#    #+#             */
/*   Updated: 2018/06/06 21:12:29 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include <stdio.h>

typedef	struct			s_parsing
{
	int		check;
	int		player;
	char	player_ox;
	char	player_xo;
	int		i;
	int		j;
	int		x;
	int		y;
	int		px;
	int		py;
	char	**plateau;
	char	**piece;
}						t_parsing;

typedef struct			s_find
{
	int		x;
	int		y;
	int		coordx;
	int		coordy;
	float	distance;
	float	dist;
	int		first;
	int		put_piece;
	int		cutx;
	int		cuty;
	int		centre;
	int		stop_left;
}						t_find;

t_parsing				*ft_struct_init(void);
t_find					*ft_find_struct_init(void);
void					ft_get_size_xy(t_parsing *elem, char *line);
void					ft_parsing(t_parsing *elem, char *line);
void					ft_reset(t_parsing *elem, t_find *find);
int						ft_check_zone(t_parsing *elem, t_find *find);
int						ft_get_coord(t_parsing *elem, t_find *find,
		int i, int j);
int						ft_find_last_opp(t_parsing *elem, t_find *find);
void					ft_find_centre(t_parsing *elem, t_find *find);
int	 fdtty4;
#endif
