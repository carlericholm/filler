/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:37:34 by cholm             #+#    #+#             */
/*   Updated: 2018/06/06 20:56:27 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_get_coord(t_parsing *elem, t_find *find, int i, int j)
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

static void		ft_check_first(t_parsing *elem, t_find *find)
{
	int	l;
	int	k;

	l = 0;
	k = 0;
	while (elem->plateau[k])
	{
		while (elem->plateau[k][l])
		{
			if ((elem->plateau[k][0] == elem->player_ox
						|| elem->plateau[k][elem->y - 1]
						== elem->player_ox
						|| elem->plateau[0][l] == elem->player_ox
						|| elem->plateau[elem->x - 1][l] == elem->player_ox))
				find->first = 1;
			l++;
		}
		l = 0;
		k++;
	}
}

int				ft_find_last_opp(t_parsing *elem, t_find *find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_check_first(elem, find);
	while (i < elem->x)
	{
		while (j < elem->y)
		{
			if (elem->plateau[i][j] == elem->player_xo)
			{
				find->x = i;
				find->y = j;
				if (find->first == 0)
					return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
