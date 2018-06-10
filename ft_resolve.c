/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:48:00 by cholm             #+#    #+#             */
/*   Updated: 2018/06/10 18:36:36 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_find_distance(t_parsing *elem, t_find *find, int i, int j)
{
	int dist_left;

	dist_left = ft_sqrt((ft_pow((elem->x / 2) - i)) + (ft_pow(0 - j)));
	if (ft_sqrt((ft_pow((elem->x / 2) - i) + ft_pow((0 - j))))
			< find->distance && find->stop_left == 0)
	{
		if (ft_sqrt((ft_pow((elem->x / 2) - i) + ft_pow((0 - j)))) > 0)
		{
			find->distance = ft_sqrt((ft_pow((elem->x / 2) - i)
						+ ft_pow((0 - j))));
			return (1);
		}
	}
	else if (ft_sqrt((ft_pow((elem->x / 2) - i) + ft_pow(((elem->y - 1) - j))))
			< find->distance && find->stop_left == 1)
	{
		if (ft_sqrt((ft_pow((elem->x / 2) - i) + ft_pow(((elem->y - 1) - j))))
				> 0)
		{
			find->distance = ft_sqrt((ft_pow((elem->x / 2) - i)
						+ ft_pow(((elem->y - 1) - j))));
			return (1);
		}
	}
	return (0);
}

void	ft_cut_x(t_parsing *elem, t_find *find)
{
	int a;
	int b;
	int k;

	a = 0;
	b = 0;
	k = 0;
	while (a < elem->px)
	{
		while (b < elem->py)
		{
			if (elem->piece[a][b] == '*')
			{
				find->cutx = a;
				k++;
				break ;
			}
			b++;
		}
		if (k == 1)
			break ;
		b = 0;
		a++;
	}
}

void	ft_cut_y(t_parsing *elem, t_find *find)
{
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	z = 0;
	while (x < elem->px)
	{
		while (y < elem->py)
		{
			if (elem->piece[x][y] == '*')
			{
				if (y < find->cuty)
				{
					find->cuty = y;
				}
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void	ft_in_while(t_parsing *elem, t_find *find, int i, int j)
{
	int check;

	check = 0;
	check = ft_get_coord(elem, find, i, j);
	if (check == 1)
	{
		if (ft_find_distance(elem, find, i, j) == 1)
		{
			find->coordx = i - find->cutx;
			find->coordy = j - find->cuty;
		}
		check = 0;
	}
}

int		ft_check_zone(t_parsing *elem, t_find *find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_find_centre(elem, find);
	ft_cut_x(elem, find);
	ft_cut_y(elem, find);
	while ((i + elem->px) <= elem->x)
	{
		while (j < elem->y)
		{
			ft_in_while(elem, find, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	ft_printf("%d %d\n", find->coordx, find->coordy);
	return (0);
}
