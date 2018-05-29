/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:03:17 by cholm             #+#    #+#             */
/*   Updated: 2018/05/08 21:24:53 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_call(unsigned long long int nbr, unsigned long long int base,
	int j, int sign)
{
	int							i;
	unsigned long long int		temp;
	char						*result;

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
			result[i] = ((temp % base) + 87);
		else
			result[i] = ((temp % base) + 48);
		temp /= base;
		i--;
	}
	if (sign < 0)
		result[0] = '-';
	return (result);
}

char	*ft_itoa_base_lower(unsigned long long int nbr, int base)
{
	int							i;
	unsigned long long int		temp;
	int							sign;
	char						*result;

	i = 1;
	sign = 1;
	temp = nbr;
	result = ft_call(nbr, base, i, sign);
	return (result);
}
