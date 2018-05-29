/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 22:44:18 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 22:46:01 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_convert(va_list args, t_point *elem)
{
	if (elem->convert == '%' || !(ft_strchr("sSpdDioOuUxXcC", elem->convert)))
		return (ft_printf_perc(elem));
	if (elem->convert == 'd' || elem->convert == 'i')
		return (ft_printf_di(args, elem));
	if (elem->convert == 'o' || elem->convert == 'u')
		return (ft_printf_ou(args, elem));
	if (elem->convert == 'p')
		return (ft_printf_p(args, elem));
	if (elem->convert == 'D')
		return (ft_printf_big_d(args, elem));
	if (elem->convert == 'O' || elem->convert == 'U')
		return (ft_printf_big_ou(args, elem));
	if (elem->convert == 'x' || elem->convert == 'X')
		return (ft_printf_x(args, elem));
	if (elem->convert == 's')
		return (ft_printf_s(args, elem));
	if (elem->convert == 'S')
		return (ft_printf_big_s(args, elem));
	if (elem->convert == 'c')
		return (ft_printf_c(args, elem));
	if (elem->convert == 'C')
		return (ft_printf_big_c(args, elem));
	return (0);
}
