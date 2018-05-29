/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:47:41 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 12:41:35 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_space(t_point *elem, char **str)
{
	char	*temp;
	char	*ptr_trash;

	ptr_trash = *str;
	if (elem->opt & (1 << 3) && str[0][0] != '-' && !(elem->opt & (1 << 1))
			&& elem->convert != '%' && elem->convert != 'u' && elem->convert
			!= 'x' && elem->convert != 'X' && elem->convert
			!= 'o' && elem->convert != 'p'
			&& elem->convert != 'c'
			&& elem->convert != 'C' && elem->convert != 'S')
	{
		temp = ft_strnew(1);
		temp[0] = ' ';
		*str = ft_strjoin(temp, *str);
		free(ptr_trash);
		free(temp);
	}
}

static void			ft_hashtag_o(t_point *elem, char **str)
{
	char	*temp;
	char	*ptr_trash;

	temp = NULL;
	ptr_trash = *str;
	if (elem->opt & (1 << 4) && (elem->convert == 'o' || elem->convert == 'O')
			&& str[0][0] != '0')
	{
		temp = ft_strnew(1);
		temp[0] = '0';
		*str = ft_strjoin(temp, *str);
		free(ptr_trash);
		free(temp);
	}
}

void				ft_hashtag(t_point *elem, char **str, int length)
{
	char	*temp;
	char	*ptr_trash;

	temp = NULL;
	ptr_trash = *str;
	if (elem->width > length && elem->opt & (1 << 2) && elem->convert != 'p'
			&& elem->convert != 'o' && elem->convert != 'O')
	{
		ft_zero(elem, str, length + 2);
		if (elem->opt & (1 << 4))
		{
			temp = ft_strnew(2);
			temp[0] = '0';
			temp[1] = 'x';
			ptr_trash = *str;
			*str = ft_strjoin(temp, *str);
			free(ptr_trash);
			free(temp);
		}
	}
	ft_hashtag_o(elem, str);
	ft_in_hash(elem, str);
}

static void			ft_help_in_hash(t_point *elem, char **str)
{
	char	*temp;
	char	*ptr_trash;

	temp = NULL;
	ptr_trash = *str;
	if (elem->opt & (1 << 4) && elem->convert == 'X' && str[0][0] != '0')
	{
		temp = ft_strnew(2);
		temp[0] = '0';
		temp[1] = 'X';
		*str = ft_strjoin(temp, *str);
		free(ptr_trash);
		free(temp);
	}
}

void				ft_in_hash(t_point *elem, char **str)
{
	char	*temp;
	char	*ptr_trash;

	temp = NULL;
	ptr_trash = *str;
	if (elem->opt & (1 << 4) && elem->convert == 'x' && str[0][0] != '0')
	{
		temp = ft_strnew(2);
		temp[0] = '0';
		temp[1] = 'x';
		*str = ft_strjoin(temp, *str);
		free(ptr_trash);
		free(temp);
	}
	if (elem->opt & (1 << 4) && elem->convert == 'x' && elem->width == 0
			&& elem->width_point > 0)
	{
		temp = ft_strnew(2);
		temp[0] = '0';
		temp[1] = 'x';
		*str = ft_strjoin(temp, *str);
		free(ptr_trash);
		free(temp);
	}
	ft_help_in_hash(elem, str);
}
