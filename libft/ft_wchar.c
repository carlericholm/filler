/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:28:55 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 21:46:36 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_onechar(wchar_t c)
{
	char	*result;

	result = ft_strnew(1);
	result[0] = c;
	return (result);
}

char		*ft_twochar(wchar_t c)
{
	char *result;

	result = ft_strnew(2);
	result[0] = ((c >> 6) & 0b11111) | 0xc0;
	result[1] = (c & 0b111111) | 0x80;
	return (result);
}

char		*ft_threechar(wchar_t c)
{
	char *result;

	result = ft_strnew(3);
	result[0] = ((c >> 12) & 0b1111) | 0xe0;
	result[1] = ((c >> 6) & 0b111111) | 0x80;
	result[2] = (c & 0b111111) | 0x80;
	return (result);
}

char		*ft_fourchar(wchar_t c)
{
	char *result;

	result = ft_strnew(4);
	result[0] = ((c >> 18) & 0b111) | 0xf0;
	result[1] = ((c >> 12) & 0b111111) | 0x80;
	result[2] = ((c >> 6) & 0b111111) | 0x80;
	result[3] = (c & 0b111111) | 0x80;
	return (result);
}

char		*ft_wchar_c(t_point *elem, wchar_t str)
{
	char *result;

	result = NULL;
	if (str == ' ')
		return (ft_strdup(" "));
	if (str > 0x00 && str < 0x7F &&
			(elem->convert == 'C' || elem->convert == 'S'))
		return (ft_onechar(str));
	if (str > 0x80 && str < 0x7FF)
		return (ft_twochar(str));
	if (str > 0x800 && str < 0xFFFF)
		return (ft_threechar(str));
	if (str > 0x10000 && str < 0x10FFFF)
		return (ft_fourchar(str));
	return (result);
}
