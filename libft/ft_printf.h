/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:38:41 by cholm             #+#    #+#             */
/*   Updated: 2018/05/20 18:19:20 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <locale.h>
# include <limits.h>
# include <unistd.h>
# include <sys/signal.h>

typedef struct			s_point
{
	int					opt;
	int					width;
	int					width_point;
	char				*options;
	char				convert;
	int					sign;
}						t_point;

typedef struct			s_parse
{
	int					i;
	int					j;
	int					result;
	int					temp;
	int					temp_bis;
}						t_parse;

int						ft_printf(const char *format, ...);
void					ft_opt(char *str, t_point *elem);
char					*ft_parse(const char *str, t_point *elem);
void					ft_width(t_point *elem);
void					ft_width_point(t_point *elem);
void					ft_size(t_point *elem);
long long int			ft_printf_di(va_list args, t_point *elem);
int						ft_printf_s(va_list args, t_point *elem);
int						ft_printf_big_s(va_list args, t_point *elem);
void					ft_sign(t_point *elem, char **str);
void					ft_space(t_point *elem, char **str);
void					ft_precision(t_point *elem, char **str, int length);
void					ft_width_flag(t_point *elem, char **str, int length);
void					ft_width_flag_s(t_point *elem, char **str, int length);
void					ft_zero(t_point *elem, char **str, int length);
int						ft_call_options(char *str, t_point *elem);
int						ft_printf_ou(va_list args, t_point *elem);
void					ft_hashtag(t_point *elem, char **str, int length);
void					ft_in_hash(t_point *elem, char **str);
long long int			ft_check_flags_di(va_list args, t_point *elem);
unsigned long long int	ft_check_flags_oux(va_list args, t_point *elem);
unsigned long long int	ft_printf_big_ou(va_list args, t_point *elem);
long long int			ft_printf_big_d(va_list args, t_point *elem);
unsigned long long int	ft_check_flags_big_ou(va_list args, t_point *elem);
long long int			ft_check_flags_big_d(va_list args, t_point *elem);
int						ft_printf_perc(t_point *elem);
int						ft_printf_c(va_list args, t_point *elem);
int						ft_printf_big_c(va_list args, t_point *elem);
int						ft_printf_p(va_list args, t_point *elem);
unsigned long long int	ft_printf_x(va_list args, t_point *elem);
void					ft_precision_s(t_point *elem, char **str, int length);
void					ft_precision_extend(t_point *elem, char *str,
		int length);
void					ft_precision_p(t_point *elem, char **str, int length);
char					*ft_wchar_c(t_point *elem, wchar_t str);
char					*ft_preci_temp(t_point *elem, int length);
int						ft_check_convert(va_list args, t_point *elem);

#endif
