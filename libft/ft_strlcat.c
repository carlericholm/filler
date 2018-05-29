/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:40:05 by cholm             #+#    #+#             */
/*   Updated: 2017/11/16 15:27:45 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t length;

	i = 0;
	j = 0;
	length = 0;
	if (n > 0)
	{
		while (dest[i] != '\0' && i < n)
			i++;
		length = i;
		while (src[j] != '\0' && i < n - 1)
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		if (length < n)
			dest[i] = '\0';
	}
	return (length + ft_strlen(src));
}
