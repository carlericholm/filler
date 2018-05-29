/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:07:35 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 22:00:06 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int		ft_printf_big_d(va_list args, t_point *elem)
{
	long long int			nbr;
	char					*str;
	int						length;

	str = NULL;
	nbr = 0;
	if (elem->opt & (1 << 7) || elem->opt & (1 << 8)
			|| elem->opt & (1 << 9) ||
			elem->opt & (1 << 10) || elem->opt & (1 << 11)
			|| elem->opt & (1 << 12))
		nbr = ft_check_flags_big_d(args, elem);
	else
		nbr = va_arg(args, long int);
	if (nbr < 0)
	{
		elem->sign = -1;
		nbr *= -1;
	}
	str = ft_itoa_upper(nbr, 10);
	length = ft_strlen(str);
	ft_hashtag(elem, &str, length);
	return (ft_call_options(str, elem));
}

int					ft_printf_big_c(va_list args, t_point *elem)
{
	wchar_t	str_bis;

	if (elem->convert == 'C')
	{
		str_bis = va_arg(args, wchar_t);
		if (str_bis == 0)
		{
			ft_putchar(0);
			return (1);
		}
		return (ft_call_options(ft_wchar_c(elem, str_bis), elem));
	}
	return (0);
}

int					ft_printf_c(va_list args, t_point *elem)
{
	char	*str;

	if (elem->opt & (1 << 9))
	{
		elem->convert = 'C';
		return (ft_printf_big_c(args, elem));
	}
	if (elem->convert == 'c')
	{
		str = ft_strnew(1);
		str[0] = va_arg(args, int);
		if (str[0] == '\0' && elem->width == 0)
		{
			ft_putchar(0);
			free(str);
			return (1);
		}
		else
			return (ft_call_options(str, elem));
	}
	return (0);
}

long long int		ft_printf_di(va_list args, t_point *elem)
{
	long long int	d;
	char			*str;

	if (elem->opt & (1 << 7) || elem->opt & (1 << 8)
			|| elem->opt & (1 << 9) ||
			elem->opt & (1 << 10) || elem->opt & (1 << 11) ||
			elem->opt & (1 << 12))
		d = ft_check_flags_di(args, elem);
	else
		d = va_arg(args, int);
	if (d < 0)
	{
		elem->sign = -1;
		d *= -1;
	}
	str = ft_itoa_upper(d, 10);
	return (ft_call_options(str, elem));
}
