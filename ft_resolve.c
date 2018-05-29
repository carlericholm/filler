/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:48:00 by cholm             #+#    #+#             */
/*   Updated: 2018/05/28 19:15:43 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"



int		ft_get_coord(t_parsing *elem, int i, int j)
{
	int k;
	int l;
	int compteur;

	k = 0;
	l = 0;
	compteur = 0;
	while (k < elem->pX)
	{
		while (l < elem->pY)
		{
			
			if (elem->piece[k][l] == '*' && (elem->plateau[i + k][j + l] == elem->player_ox))
				compteur++;
			if (elem->piece[k][l] == '*' && (elem->plateau[i + k][j + l] == elem->player_xo))
				compteur += 2;
			if (elem->plateau[i + k][j + l] == '\0')
				compteur += 2;
			l++;
		}
		l = 0;
		k++;
	}
	if (compteur == 1)
		return (1);
	return (0);
}


int		ft_find_last_opp(t_parsing *elem, t_find *find)
{
	int i;
	int j;
	int fdtty4;

	i = 0;
	j = 0;
	fdtty4 = open("/dev/ttys004", O_WRONLY);
	while (i < elem->X)
	{
		while (j < elem->Y)
		{
			if (elem->plateau[i][j] == 'X')
			{
				find->x = i;
				find->y = j;
				//dprintf(fdtty4 ,"X adv -> %d\nY adv -> %d\n", find->x, find->y);
				return (0);
			}	
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int 		ft_find_distance(t_find *find, int i, int j)
{

	int fdtty4;
	float test;

	test = ft_sqrt((ft_pow(find->x - i) + ft_pow((find->y - j))));

	fdtty4 = open("/dev/ttys004", O_WRONLY);
	if (ft_sqrt((ft_pow(find->x - i) + ft_pow((find->y - j)))) < find->distance)
	{
		if (ft_sqrt((ft_pow(find->x - i) + ft_pow((find->y - j)))) > 0)
			find->distance = ft_sqrt((ft_pow(find->x - i) + ft_pow((find->y - j))));
		dprintf(fdtty4, "distance -> %f\n", test);	
		return (1);
	}
	else
		return (0);
	return (0);	
}

int 	ft_check_zone(t_parsing *elem, t_find *find)
{
	int i;
	int j;
	int check;
	int fdtty4;

	i = 0;
	j = 0;
	check = 0;

	ft_find_last_opp(elem, find);
	fdtty4 = open("/dev/ttys004", O_WRONLY);
	while (i < elem->X)
	{
		while (j < elem->Y)
		{
			check = ft_get_coord(elem, i, j);

			if (check == 1)
			{
				if (ft_find_distance(find, i, j) == 1)
				{
					find->coordx = i;
					find->coordy = j;
				}
				//dprintf(fdtty4 ,"i -> %d\nj -> %d\n", find->coordx, find->coordy);
				check = 0;
			}
			j++;
		}
		j = 0;
		i++;
		dprintf(fdtty4, "OK\n");
	}


	elem->i = 0;	
	elem->j = 0;
	elem->player = 0;
	elem->X = 0;
	elem->Y = 0;
	elem->pX = -1;
	elem->pY = 0;
	elem->plateau = NULL;
	elem->piece = NULL;

	

	find->x = 0;
	find->y = 0;
	ft_printf("%d %d\n", find->coordx, find->coordy);
	dprintf(fdtty4, "distance finale-> %f\n", find->distance);
	find->distance = 200;
	find->coordx = 0;
	find->coordy = 0;
	return (0);
}
