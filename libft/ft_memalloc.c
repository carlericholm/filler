/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:27:01 by cholm             #+#    #+#             */
/*   Updated: 2017/11/14 17:55:39 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *str;

	if (size > 4294967295)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) * size)))
	{
		return (NULL);
	}
	ft_bzero(str, size);
	return (str);
}
