/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_big_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:34:09 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 23:35:39 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_help_big_s(char **temp_bis)
{
	ft_putstr("(null)");
	free(*temp_bis);
	return (6);
}

int				ft_printf_big_s(va_list args, t_point *elem)
{
	wchar_t	*str_bis;
	int		i;
	char	*temp;
	char	*temp_bis;
	char	*ptr_trash;

	i = 0;
	temp_bis = ft_strnew(1);
	if (elem->convert == 'S')
	{
		str_bis = va_arg(args, wchar_t *);
		if (str_bis == NULL)
			return (ft_help_big_s(&temp_bis));
		while (str_bis[i])
		{
			ptr_trash = temp_bis;
			temp = ft_wchar_c(elem, str_bis[i]);
			temp_bis = ft_strjoin(temp_bis, temp);
			free(ptr_trash);
			free(temp);
			i++;
		}
		return (ft_call_options(temp_bis, elem));
	}
	return (0);
}
