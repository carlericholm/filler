/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:34:40 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 12:47:07 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_width_flag(t_point *elem, char **str, int length)
{
	char		*temp;
	int			i;
	int			largeur;
	char		*ptr_trash;

	i = 0;
	ptr_trash = *str;
	if (elem->width > elem->width_point
			&& elem->width > length && !(elem->opt & (1 << 2)))
	{
		largeur = elem->width - length;
		temp = ft_strnew(largeur);
		while (i < (largeur))
		{
			temp[i] = ' ';
			i++;
		}
		if (elem->opt & (1 << 0))
			*str = ft_strjoin(*str, temp);
		else
			*str = ft_strjoin(temp, *str);
		free(ptr_trash);
		free(temp);
	}
}

void			ft_in_width_s(t_point *elem, char **str, int length)
{
	char		*temp;
	int			i;
	int			largeur;
	char		*ptr_trash;

	i = 0;
	ptr_trash = *str;
	largeur = elem->width - length;
	temp = ft_strnew(largeur);
	while (i < (largeur))
	{
		if (elem->opt & (1 << 2))
			temp[i] = '0';
		else
			temp[i] = ' ';
		i++;
	}
	if (elem->opt & (1 << 0))
		*str = ft_strjoin(*str, temp);
	else
		*str = ft_strjoin(temp, *str);
	free(ptr_trash);
	free(temp);
}

static char		*ft_help_width_flag_s(t_point *elem, int length)
{
	char		*temp;
	int			i;
	int			largeur;

	i = 0;
	largeur = elem->width - length;
	temp = ft_strnew(largeur);
	while (i < (largeur))
	{
		if (elem->opt & (1 << 2))
			temp[i] = '0';
		else
			temp[i] = ' ';
		i++;
	}
	return (temp);
}

void			ft_width_flag_s(t_point *elem, char **str, int length)
{
	char		*temp;
	char		*ptr_trash;

	ptr_trash = *str;
	if (elem->width > elem->width_point && elem->width > length)
	{
		temp = ft_help_width_flag_s(elem, length);
		if (elem->opt & (1 << 0))
			*str = ft_strjoin(*str, temp);
		else
			*str = ft_strjoin(temp, *str);
		free(temp);
		free(ptr_trash);
	}
	else if (elem->width < elem->width_point && elem->width > length)
		ft_in_width_s(elem, &*str, length);
}
