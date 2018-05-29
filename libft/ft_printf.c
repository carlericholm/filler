/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:10:12 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 23:41:10 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_point			*ft_init(void)
{
	t_point *elem;

	elem = (t_point *)malloc(sizeof(t_point));
	elem->opt = 0;
	elem->width = 0;
	elem->width_point = 0;
	elem->options = NULL;
	elem->convert = 0;
	elem->sign = 1;
	return (elem);
}

t_parse			*ft_parse_init(void)
{
	t_parse *parse;

	parse = (t_parse *)malloc(sizeof(t_parse));
	parse->i = 0;
	parse->j = 0;
	parse->result = 0;
	parse->temp = 0;
	parse->temp_bis = 0;
	return (parse);
}

void			ft_help_printf(t_point *elem, t_parse *parse, va_list args)
{
	elem->opt = 0;
	ft_opt(elem->options, elem);
	ft_width(elem);
	ft_width_point(elem);
	ft_size(elem);
	parse->result = ft_check_convert(args, elem);
	parse->temp += parse->result;
	parse->temp_bis--;
	while (elem->options[parse->j] != '\0')
		parse->j++;
	parse->i = parse->i + parse->j + 1;
}

static void		*ft_increase(t_point *elem, t_parse *parse)
{
	parse->i++;
	parse->temp_bis++;
	parse->j = 0;
	elem->width = 0;
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	t_point	*elem;
	t_parse *parse;

	va_start(args, format);
	elem = ft_init();
	parse = ft_parse_init();
	while (format[parse->i] != '\0')
	{
		if (format[parse->i] == '%')
		{
			if (format[parse->i + 1] == '\0')
				break ;
			elem->options = ft_parse(format + (parse->i + 1), elem);
			ft_help_printf(elem, parse, args);
			free(elem->options);
		}
		else
			ft_putchar(format[parse->i]);
		ft_increase(elem, parse);
	}
	va_end(args);
	free(elem);
	free(parse);
	return (parse->temp + parse->temp_bis);
}
