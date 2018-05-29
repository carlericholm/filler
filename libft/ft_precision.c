/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:54:54 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 17:29:25 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_in_prec(t_point *elem, char **str)
{
	if (elem->opt & (1 << 4) && elem->opt & (1 << 6) &&
			elem->width_point == 0)
		return ;
	if (elem->width_point == 0 && elem->convert != 'd')
		*str[0] = '\0';
	if (elem->width_point == 0 && elem->convert == 'd' && str[0][0] == '0')
		*str[0] = '\0';
}

char	*ft_preci_temp(t_point *elem, int length)
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

void	ft_precision(t_point *elem, char **str, int length)
{
	int		i;
	char	*temp;
	char	*ptr_trash;

	i = 0;
	ptr_trash = *str;
	if (elem->opt & (1 << 6) && elem->convert != '%' && elem->convert
			!= 'c' && elem->convert != 'C')
	{
		ft_in_prec(elem, &*str);
		if (elem->width_point > length)
		{
			temp = ft_preci_temp(elem, length);
			*str = ft_strjoin(temp, *str);
			free(temp);
			free(ptr_trash);
			if (!(elem->opt & (1 << 1)))
			{
				ft_sign(elem, str);
				elem->sign = 1;
			}
		}
	}
}
