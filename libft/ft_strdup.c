/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:25:09 by cholm             #+#    #+#             */
/*   Updated: 2017/11/13 18:01:05 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (str != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
