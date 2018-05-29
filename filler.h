/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 10:51:02 by cholm             #+#    #+#             */
/*   Updated: 2018/05/23 22:10:22 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

typedef	struct			s_parsing
{
	int		player;
	char	player_ox;
	char	player_xo;
	int		i;
	int		j;
	int		X;
	int		Y;
	int		pX;
	int		pY;
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
}						t_find;

int 	ft_check_zone(t_parsing *elem, t_find *find);
