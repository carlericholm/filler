/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:14:36 by cholm             #+#    #+#             */
/*   Updated: 2017/11/15 21:47:55 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
		i++;
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
