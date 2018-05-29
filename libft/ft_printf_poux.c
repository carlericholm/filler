/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_poux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:13:57 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 23:00:52 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							ft_printf_ou(va_list args, t_point *elem)
{
	unsigned long long int	nbr;
	char					*str;
	int						length;

	str = NULL;
	nbr = 0;
	if (elem->opt & (1 << 7) || elem->opt & (1 << 8) || elem->opt & (1 << 9) ||
			elem->opt & (1 << 10) || elem->opt & (1 << 11)
			|| elem->opt & (1 << 12))
		nbr = ft_check_flags_oux(args, elem);
	else
		nbr = va_arg(args, unsigned int);
	if (elem->convert == 'o')
		str = ft_itoa_upper(nbr, 8);
	if (elem->convert == 'u')
		str = ft_itoa_upper(nbr, 10);
	length = ft_strlen(str);
	ft_hashtag(elem, &str, length);
	return (ft_call_options(str, elem));
}

static char					*ft_help_print_p(void)
{
	char	*temp;

	temp = ft_strnew(2);
	temp[0] = '0';
	temp[1] = 'x';
	return (temp);
}

int							ft_printf_p(va_list args, t_point *elem)
{
	unsigned long long int	nbr;
	char					*str;
	char					*temp;
	char					*ptr_trash;

	str = NULL;
	nbr = 0;
	nbr = va_arg(args, unsigned long long int);
	if (elem->convert == 'p')
		str = ft_itoa_base_lower(nbr, 16);
	if (str[0] == '0' && elem->opt & (1 << 6) && elem->width_point == 0)
	{
		ft_putstr("0x");
		free(str);
		return (2);
	}
	temp = ft_help_print_p();
	if (elem->opt & (1 << 6))
		ft_precision_p(elem, &str, ft_strlen(str));
	ptr_trash = str;
	str = ft_strjoin(temp, str);
	ft_hashtag(elem, &str, ft_strlen(str));
	free(temp);
	free(ptr_trash);
	return (ft_call_options(str, elem));
}

unsigned long long int		ft_printf_big_ou(va_list args, t_point *elem)
{
	unsigned long long int	nbr;
	char					*str;
	int						length;

	str = NULL;
	nbr = 0;
	if (elem->opt & (1 << 7) || elem->opt & (1 << 8)
			|| elem->opt & (1 << 9) ||
			elem->opt & (1 << 10) || elem->opt & (1 << 11)
			|| elem->opt & (1 << 12))
		nbr = ft_check_flags_big_ou(args, elem);
	else
		nbr = va_arg(args, unsigned long int);
	if (elem->convert == 'O')
		str = ft_itoa_upper(nbr, 8);
	if (elem->convert == 'U' || elem->convert == 'D')
		str = ft_itoa_upper(nbr, 10);
	length = ft_strlen(str);
	ft_hashtag(elem, &str, length);
	return (ft_call_options(str, elem));
}

unsigned long long int		ft_printf_x(va_list args, t_point *elem)
{
	unsigned long long int	nbr;
	char					*str;
	int						length;

	str = NULL;
	nbr = 0;
	if (elem->opt & (1 << 7) || elem->opt & (1 << 8) || elem->opt & (1 << 9) ||
	elem->opt & (1 << 10) || elem->opt & (1 << 11) || elem->opt & (1 << 12))
		nbr = ft_check_flags_oux(args, elem);
	else
		nbr = va_arg(args, unsigned int);
	if (elem->convert == 'x')
		str = ft_itoa_base_lower(nbr, 16);
	if (elem->convert == 'X')
		str = ft_itoa_upper(nbr, 16);
	length = ft_strlen(str);
	if (str[0] == '0' && elem->opt & (1 << 6) && elem->opt & (1 << 4))
	{
		free(str);
		return (0);
	}
	ft_precision(elem, &str, length);
	ft_hashtag(elem, &str, length);
	return (ft_call_options(str, elem));
}
