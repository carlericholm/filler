/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:17:08 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 12:19:13 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_help_in_zero(t_point *elem, int length)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strnew(elem->width - length);
	while (i < (elem->width - length))
	{
		if (!(elem->opt & (1 << 6)) && !(elem->opt & (1 << 0)))
			temp[i] = '0';
		else if ((elem->convert == 'c' || elem->convert == '%'
					|| elem->convert == 'S') && elem->width_point == 0)
			temp[i] = '0';
		else
			temp[i] = ' ';
		i++;
	}
	return (temp);
}

static void		ft_in_zero(t_point *elem, char **str, int length)
{
	char	*temp;
	char	*ptr_trash;

	ptr_trash = *str;
	if (elem->width > length)
	{
		if (elem->opt & (1 << 1) && elem->opt & (1 << 6)
				&& elem->convert == 'd')
			length--;
		temp = ft_help_in_zero(elem, length);
		if (elem->opt & (1 << 0) || elem->convert == 'p')
			*str = ft_strjoin(*str, temp);
		else
			*str = ft_strjoin(temp, *str);
		free(ptr_trash);
		free(temp);
	}
}

void			ft_zero(t_point *elem, char **str, int length)
{
	int	i;

	i = 0;
	if (length == 0 && elem->convert == 'c')
		length++;
	if (elem->sign < 0 || elem->opt & (1 << 3) || elem->opt & (1 << 1))
		length++;
	if (elem->opt & (1 << 2))
		ft_in_zero(elem, str, length);
}
