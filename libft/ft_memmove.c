/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:55:58 by cholm             #+#    #+#             */
/*   Updated: 2017/11/17 17:27:50 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char temp[n];

	if (n < 134217728)
	{
		ft_memcpy(temp, src, n);
		ft_memcpy(dest, temp, n);
		return (dest);
	}
	return (0);
}
