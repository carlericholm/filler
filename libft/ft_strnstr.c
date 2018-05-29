/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:24:15 by cholm             #+#    #+#             */
/*   Updated: 2017/11/16 16:47:33 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t temp;

	i = 0;
	j = 0;
	if (!s2[i])
		return ((char *)s1);
	while (s1[i] != '\0' && j < n)
	{
		j = 0;
		temp = i;
		while ((s2[j] == s1[i]) && (i < n) && (s1[i]))
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + temp);
		i = temp;
		i++;
	}
	return (0);
}
