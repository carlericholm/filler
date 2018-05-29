/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:20:44 by cholm             #+#    #+#             */
/*   Updated: 2018/04/24 11:18:01 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_test(int nbr, int base, int j, int sign)
{
	int		i;
	int		temp;
	char	*result;

	i = j;
	temp = nbr;
	while ((nbr /= base) > 0)
		i++;
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i] = '\0';
	i--;
	while (i >= 0)
	{
		if ((temp % base) > 9)
			result[i] = ((temp % base) + 55);
		else
			result[i] = ((temp % base) + 48);
		temp /= base;
		i--;
	}
	if (sign < 0)
		result[0] = '-';
	return (result);
}

char	*ft_itoa_base(int nbr, int base)
{
	int		i;
	int		temp;
	int		sign;
	char	*result;

	i = 1;
	sign = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		sign = -1;
		i++;
	}
	temp = nbr;
	result = ft_test(nbr, base, i, sign);
	return (result);
}
