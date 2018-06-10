/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:44:21 by cholm             #+#    #+#             */
/*   Updated: 2018/06/06 21:32:32 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_malloc_plateau(t_parsing *elem)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (elem->plateau == NULL && elem->x > 0 && elem->y > 0)
	{
		if (!(elem->plateau = (char **)malloc(sizeof(char *) * (elem->x + 1))))
			return (0);
		elem->plateau[elem->x] = 0;
		while (i < elem->x)
		{
			if (!(elem->plateau[i] = (char *)malloc(sizeof(char)
							* (elem->y + 1))))
				return (0);
			elem->plateau[i][elem->y] = '\0';
			i++;
		}
	}
	return (0);
}

void		ft_fill_plateau(t_parsing *elem, char *line)
{
	int i;
	int j;

	if (line[0] == '0' && elem->x > 0 && elem->y > 0)
	{
		i = 0;
		j = 4;
		while (line[j] != '\0')
		{
			elem->plateau[elem->i][i] = line[j];
			j++;
			i++;
		}
		elem->i++;
	}
}

int			ft_malloc_piece(t_parsing *elem)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (elem->piece == NULL && elem->px > 0 && elem->py > 0)
	{
		if (!(elem->piece = (char **)malloc(sizeof(char *) * (elem->px + 1))))
			return (0);
		elem->piece[elem->px] = 0;
		while (i < elem->px)
		{
			if (!(elem->piece[i] = (char *)malloc(sizeof(char)
							* (elem->py + 1))))
				return (0);
			elem->piece[i][elem->py] = '\0';
			i++;
		}
	}
	return (0);
}

void		ft_fill_piece(t_parsing *elem, char *line)
{
	int i;

	if ((line[0] == '.' || line[0] == '*') && (elem->px > 0 && elem->py > 0))
	{
		i = 0;
		while (line[i] != '\0')
		{
			elem->piece[elem->j][i] = line[i];
			i++;
		}
		elem->j++;
	}
}

int			main(void)
{
	char		*line;
	t_parsing	*elem;
	t_find		*find;
	fdtty4 = open("/dev/ttys004", O_WRONLY);
	elem = ft_struct_init();
	find = ft_find_struct_init();
	while (elem->check == 1)
	{
		get_next_line(0, &line);
		ft_parsing(elem, line);
		ft_malloc_plateau(elem);
		ft_malloc_piece(elem);
		ft_fill_plateau(elem, line);
		ft_fill_piece(elem, line);
		if (elem->j == elem->px)
		{
			ft_check_zone(elem, find);
			ft_free_tab(elem->plateau);
			ft_free_tab(elem->piece);
			ft_reset(elem, find);
		}
		ft_strdel(&line);
	}
	free(elem);
	free(find);
return (0);
}
