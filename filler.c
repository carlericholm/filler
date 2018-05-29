/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:44:21 by cholm             #+#    #+#             */
/*   Updated: 2018/05/28 19:31:25 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_parsing		*ft_struct_init(void)
{
	t_parsing		*elem;

	elem = (t_parsing *)malloc(sizeof(t_parsing));
	elem->i = 0;
	elem->j = 0;
	elem->player = 0;
	elem->X = 0;
	elem->Y = 0;
	elem->pX = -1;
	elem->pY = 0;
	elem->plateau = NULL;
	elem->piece = NULL;
	elem->player_ox = 0;
	elem->player_xo = 0;
	return (elem);
}


t_find			*ft_find_struct_init(void)
{
	t_find		*find;

	find = (t_find *)malloc(sizeof(t_find));
	find->x = 0;
	find->y = 0;
	find->coordx = 0;
	find->coordy = 0;
	find->distance = 200;
	return (find);
}

void		ft_get_size_xy(t_parsing *elem, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (line[1] == 'l')
				elem->X = ft_atoi(&line[i]);
			if (line[1] == 'i')
				elem->pX = ft_atoi(&line[i]);
			while (ft_isdigit(line[i]))
				i++;
			if (line[i] == ' ' && ft_isdigit(line[i + 1]))
			{
				if (line[1] == 'l')
					elem->Y = ft_atoi(&line[i + 1]);
				if (line[1] == 'i')
					elem->pY = ft_atoi(&line[i]);
				break ;
			}
		}
		i++;
	}
}

void		ft_parsing(t_parsing *elem, char *line)
{
	int fdtty4;
	int i;

	i = 0;
	fdtty4 = open("/dev/ttys004", O_WRONLY);
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
	//dprintf(fdtty4, "Map X: %d\n Map y: %d\n Piece X: %d\n Piece Y: %d\n",
//			elem->X, elem->Y, elem->pX, elem->pY);
}

int		ft_malloc_plateau(t_parsing *elem, char *line)
{
	int i;
	int j;
	int fdtty4;

	i = 0;
	j = 0;
	fdtty4 = open("/dev/ttys004", O_WRONLY);
	if (elem->plateau == NULL && elem->X > 0 && elem->Y > 0)
	{
		if (!(elem->plateau = (char **)malloc(sizeof(char *) * (elem->X + 1))))
			return (0);
		elem->plateau[elem->X] = 0;
		while (i < elem->X)
		{
			if(!(elem->plateau[i] = (char *)malloc(sizeof(char) * (elem->Y + 1))))
				return (0);
			elem->plateau[i][elem->Y] = '\0';
			i++;
		}
		
	}
		return (0);
}

void		ft_fill_plateau(t_parsing *elem, char *line)
{
	int i;
	int j;
	int fdtty4;

	fdtty4 = open("/dev/ttys004", O_WRONLY);

	if (line[0] == '0')
	{
		i = 0;
		j = 4;
		while (line[j] != '\0')
		{
			elem->plateau[elem->i][i] = line[j];
			j++;
			i++;
		}
		dprintf(fdtty4, "%s\n", elem->plateau[elem->i]);
		elem->i++;
	}
}


int		ft_malloc_piece(t_parsing *elem, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (elem->piece == NULL && elem->pX > 0 && elem->pY > 0)
	{
		if (!(elem->piece = (char **)malloc(sizeof(char *) * (elem->pX + 1))))
			return (0);
		elem->piece[elem->pX] = 0;
		while (i < elem->pX)
		{
			if(!(elem->piece[i] = (char *)malloc(sizeof(char) * (elem->pY + 1))))
				return (0);
			elem->piece[i][elem->pY] = '\0';
			i++;
		}	
	}
	return (0);
}


void		ft_fill_piece(t_parsing *elem, char *line)
{
	int i;
	int j;
	int fdtty4;

	fdtty4 = open("/dev/ttys004", O_WRONLY);

	if (line[0] == '.' || line[0] == '*')
	{
		i = 0;
		while (line[i] != '\0')
		{
			elem->piece[elem->j][i] = line[i];
			i++;
		}
		elem->j++;
	//	dprintf(fdtty4, "%sj--->%d\n", elem->piece[elem->j - 1], elem->j);
	}
}

int			main(void)
{
	char	*line;
	int		ret;
	int		end;
	t_parsing *elem;
	t_find		*find;
	int fdtty4;

	
	fdtty4 = open("/dev/ttys004", O_WRONLY);
	end = 1;
	elem = ft_struct_init();
	find = ft_find_struct_init();
	while (1)
	{
		get_next_line(0, &line);
		ft_parsing(elem, line);
		ft_malloc_plateau(elem, line);
		ft_malloc_piece(elem, line);
		ft_fill_plateau(elem, line);
		ft_fill_piece(elem, line);
		if (elem->j == elem->pX)
		{
			end = ft_check_zone(elem, find);
		//	sleep(3);
		}
	}
}
