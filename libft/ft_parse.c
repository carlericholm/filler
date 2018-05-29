/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:05:05 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 16:17:51 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_opt(char *str, t_point *elem)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			elem->opt = elem->opt | (1 << 0);
		if (str[i] == '+')
			elem->opt = elem->opt | (1 << 1);
		if (str[i] == '0' && !(ft_isdigit(str[i - 1])))
			elem->opt = elem->opt | (1 << 2);
		if (str[i] == ' ')
			elem->opt = elem->opt | (1 << 3);
		if (str[i] == '#')
			elem->opt = elem->opt | (1 << 4);
		if (str[i] == '*')
			elem->opt = elem->opt | (1 << 5);
		if (str[i] == '.')
			elem->opt = elem->opt | (1 << 6);
		i++;
	}
}

char		*ft_parse(const char *str, t_point *elem)
{
	int		i;
	int		j;
	char	*flags;
	char	*options;

	flags = "-+#*. hljz";
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(flags, str[i]) || ft_isdigit(str[i]))
			i++;
		else
			break ;
	}
	options = ft_strnew(i);
	while (j < i)
	{
		options[j] = str[j];
		j++;
	}
	elem->convert = str[j];
	return (options);
}

void		ft_width(t_point *elem)
{
	int		i;
	char	*str;

	i = 0;
	str = elem->options;
	while (str[i])
	{
		if ((ft_atoi(str + i) != 0) && ft_isdigit(str[i]) && str[i - 1] != '.')
		{
			elem->width = ft_atoi(str + i);
			break ;
		}
		i++;
	}
}

void		ft_width_point(t_point *elem)
{
	int		i;
	char	*str;

	i = 0;
	str = elem->options;
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			elem->width_point = ft_atoi(str + i);
			break ;
		}
		i++;
	}
}

void		ft_size(t_point *elem)
{
	int		i;
	char	*str;
	char	*flags;

	i = 0;
	flags = "hljz*";
	str = elem->options;
	while (str[i])
	{
		if (str[i] == 'h' && str[i + 1] != 'h' && str[i - 1] != 'h')
			elem->opt = elem->opt | (1 << 7);
		if (str[i] == 'h' && str[i + 1] == 'h')
			elem->opt = elem->opt | (1 << 8);
		if (str[i] == 'l' && str[i + 1] != 'l' && str[i - 1] != 'l')
			elem->opt = elem->opt | (1 << 9);
		if (str[i] == 'l' && str[i + 1] == 'l')
			elem->opt = elem->opt | (1 << 10);
		if (str[i] == 'j')
			elem->opt = elem->opt | (1 << 11);
		if (str[i] == 'z')
			elem->opt = elem->opt | (1 << 12);
		if (str[i] == '*')
			elem->opt = elem->opt | (1 << 13);
		i++;
	}
}
