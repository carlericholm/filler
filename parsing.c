/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 21:04:37 by cholm             #+#    #+#             */
/*   Updated: 2018/06/06 21:18:01 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_parsing		*ft_struct_init(void)
{
	t_parsing	*elem;

	elem = (t_parsing *)malloc(sizeof(t_parsing));
	elem->i = 0;
	elem->j = 0;
	elem->player = 0;
	elem->x = 0;
	elem->y = 0;
	elem->px = -1;
	elem->py = 0;
	elem->plateau = NULL;
	elem->piece = NULL;
	elem->player_ox = 0;
	elem->player_xo = 0;
	return (elem);
}

t_find			*ft_find_struct_init(void)
{
	t_find	*find;

	find = (t_find *)malloc(sizeof(t_find));
	find->x = 0;
	find->y = 0;
	find->coordx = 0;
	find->coordy = 0;
	find->distance = 200;
	find->first = 0;
	find->put_piece = 0;
	find->cutx = 0;
	find->cuty = 0;
	return (find);
}

void			ft_get_size_xy(t_parsing *elem, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (line[1] == 'l')
				elem->x = ft_atoi(&line[i]);
			if (line[1] == 'i')
				elem->px = ft_atoi(&line[i]);
			while (ft_isdigit(line[i]))
				i++;
			if (line[i] == ' ' && ft_isdigit(line[i + 1]))
			{
				if (line[1] == 'l')
					elem->y = ft_atoi(&line[i + 1]);
				if (line[1] == 'i')
					elem->py = ft_atoi(&line[i]);
				break ;
			}
		}
		i++;
	}
}

void			ft_parsing(t_parsing *elem, char *line)
{
	int	i;

	i = 0;
	if (!line[0])
		exit(1);
	if (line[0] == '$')
	{
		elem->player = ft_atoi(&line[10]);
		if (elem->player == 1)
		{
			elem->player_ox = 'O';
			elem->player_xo = 'X';
		}
		if (elem->player == 2)
		{
			elem->player_ox = 'X';
			elem->player_xo = 'O';
		}
	}
	if (line[0] == 'P' && line[1] == 'l')
		ft_get_size_xy(elem, line);
	if (line[0] == 'P' && line[1] == 'i')
		ft_get_size_xy(elem, line);
}

void			ft_reset(t_parsing *elem, t_find *find)
{
	elem->i = 0;
	elem->j = 0;
	elem->player = 0;
	elem->x = 0;
	elem->y = 0;
	elem->px = -1;
	elem->py = 0;
	elem->plateau = NULL;
	elem->piece = NULL;
	find->x = 0;
	find->y = 0;
	find->distance = 200;
	find->coordx = 0;
	find->coordy = 0;
	find->cutx = 0;
	find->cuty = 200;
}
