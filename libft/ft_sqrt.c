/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:14:53 by cholm             #+#    #+#             */
/*   Updated: 2018/05/23 20:45:41 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_sqrt(float nbr)
{
	float temp;
	float sqrt;

	sqrt = nbr / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = ((nbr / temp + temp) / 2);
	}
	return (sqrt);
}
