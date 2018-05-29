/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precisions_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:00:22 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 12:03:47 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_in_p_prec(t_point *elem, int length)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strnew(elem->width_point - length);
	while (i < (elem->width_point - length))
	{
		temp[i] = '0';
		i++;
	}
	return (temp);
}

void	ft_precision_p(t_point *elem, char **str, int length)
{
	int		i;
	char	*temp;
	char	*ptr_trash;

	i = 0;
	ptr_trash = *str;
	if (elem->width < elem->width_point)
	{
		if (elem->width == 0)
		{
			temp = ft_strnew(elem->width_point - 1);
			while (i < (elem->width_point - 1))
			{
				temp[i] = '0';
				i++;
			}
		}
		else
			temp = ft_in_p_prec(elem, length);
		*str = ft_strjoin(temp, *str);
		free(temp);
		free(ptr_trash);
	}
	else
		return ;
}

void	ft_precision_s(t_point *elem, char **str, int length)
{
	int		i;
	int		test;
	char	*ptr_trash;

	i = 0;
	ptr_trash = *str;
	test = length;
	if (elem->opt & (1 << 6) && elem->convert != '%')
	{
		*str = ft_strsub(*str, 0, elem->width_point);
		free(ptr_trash);
	}
}
