/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:17:40 by cholm             #+#    #+#             */
/*   Updated: 2017/11/15 22:01:19 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	int		size;
	char	*str;

	j = 0;
	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	size = i;
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	i = 0;
	while (j < size)
	{
		str[i] = f(j, s[i]);
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
