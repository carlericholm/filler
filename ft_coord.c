/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:37:34 by cholm             #+#    #+#             */
/*   Updated: 2018/06/10 18:29:19 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_get_coord(t_parsing *elem, t_find *find, int i, int j)
{
	int	k;
	int	l;
	int	compteur;

	k = 0;
	l = 0;
	compteur = 0;
	while ((k + find->cutx) < elem->px)
	{
		while ((l + find->cuty) < elem->py)
		{
			if (elem->piece[k + find->cutx][l + find->cuty] == '*'
					&& (elem->plateau[i + k][j + l] == elem->player_ox))
				compteur++;
			if (elem->piece[k + find->cutx][l + find->cuty] == '*'
					&& (elem->plateau[i + k][j + l] == elem->player_xo))
				compteur += 2;
			if (elem->plateau[i + k][j + l] == '\0')
				compteur += 2;
			l++;
		}
		l = 0;
		k++;
	}
	return (compteur == 1 ? 1 : 0);
}

void		ft_find_centre(t_parsing *elem, t_find *find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	find->x = (elem->x / 2);
	find->y = (elem->y / 2);
	while (i < elem->x)
	{
		while (j < elem->y)
		{
			if ((i == (elem->x / 2)) && (j == elem->y / 2)
					&& (elem->plateau[i][j] == elem->player_ox
					|| elem->plateau[i][j] == elem->player_xo))
				find->centre = 1;
			if (elem->plateau[i][0] == elem->player_ox)
				find->stop_left = 1;
			j++;
		}
		j = 0;
		i++;
	}
}
