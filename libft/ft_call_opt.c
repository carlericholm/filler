/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 21:55:55 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 21:57:40 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_help_call_options(char *str, t_point *elem)
{
	int	length;

	str[elem->width - 1] = '\0';
	ft_putstr(str);
	ft_putchar(0);
	length = ft_strlen(str);
	free(str);
	return (length + 1);
}

int				ft_call_options(char *str, t_point *elem)
{
	int	length;

	length = 0;
	ft_precision(elem, &str, ft_strlen(str));
	if (!(elem->opt & (1 << 6)))
		ft_zero(elem, &str, ft_strlen(str));
	ft_sign(elem, &str);
	if (elem->opt & (1 << 6))
		ft_zero(elem, &str, ft_strlen(str));
	ft_space(elem, &str);
	ft_width_flag(elem, &str, ft_strlen(str));
	if (elem->convert == 'c' && str[elem->width - 1] == ' ' && str[0] == ' ')
		return (ft_help_call_options(str, elem));
	ft_putstr(str);
	if (elem->convert == 'c' && elem->opt & (1 << 2) && str[0] == '0')
	{
		ft_putchar(0);
		length = ft_strlen(str);
		free(str);
		return (length + 1);
	}
	length = ft_strlen(str);
	free(str);
	return (length);
}
