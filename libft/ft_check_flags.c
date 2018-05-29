/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:05:41 by cholm             #+#    #+#             */
/*   Updated: 2018/05/08 16:29:17 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int		ft_check_flags_big_ou(va_list args, t_point *elem)
{
	unsigned long long int	result;

	result = 0;
	if (elem->opt & (1 << 7))
		result = va_arg(args, unsigned long long int);
	if (elem->opt & (1 << 8))
		result = va_arg(args, unsigned long int);
	if (elem->opt & (1 << 9))
		result = va_arg(args, long unsigned int);
	if (elem->opt & (1 << 10))
		result = va_arg(args, unsigned long long int);
	if (elem->opt & (1 << 11))
		result = (unsigned long long)va_arg(args, intmax_t);
	if (elem->opt & (1 << 12))
		result = va_arg(args, size_t);
	return (result);
}

unsigned long long int		ft_check_flags_oux(va_list args, t_point *elem)
{
	unsigned long long int	result;

	result = 0;
	if (elem->opt & (1 << 7))
		result = (short unsigned int)va_arg(args, unsigned int);
	if (elem->opt & (1 << 8))
		result = (unsigned char)va_arg(args, unsigned long int);
	if (elem->opt & (1 << 9))
		result = va_arg(args, long unsigned int);
	if (elem->opt & (1 << 10))
		result = va_arg(args, unsigned long long int);
	if (elem->opt & (1 << 11))
		result = (unsigned long long)va_arg(args, intmax_t);
	if (elem->opt & (1 << 12))
		result = va_arg(args, size_t);
	return (result);
}

long long int				ft_check_flags_big_d(va_list args, t_point *elem)
{
	long long int	result;

	result = 4;
	if (elem->opt & (1 << 7))
		result = va_arg(args, long int);
	if (elem->opt & (1 << 8))
		result = va_arg(args, long int);
	if (elem->opt & (1 << 9))
		result = va_arg(args, long int);
	if (elem->opt & (1 << 10))
		result = va_arg(args, long long int);
	if (elem->opt & (1 << 11))
		result = (long long)va_arg(args, intmax_t);
	if (elem->opt & (1 << 12))
		result = va_arg(args, size_t);
	return (result);
}

long long int				ft_check_flags_di(va_list args, t_point *elem)
{
	long long int	result;

	result = 4;
	if (elem->opt & (1 << 7))
		result = (short int)va_arg(args, int);
	if (elem->opt & (1 << 8))
		result = (char)va_arg(args, int);
	if (elem->opt & (1 << 9))
		result = va_arg(args, long int);
	if (elem->opt & (1 << 10))
		result = va_arg(args, long long int);
	if (elem->opt & (1 << 11))
		result = (long long)va_arg(args, intmax_t);
	if (elem->opt & (1 << 12))
		result = va_arg(args, size_t);
	return (result);
}
