/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:37:54 by cholm             #+#    #+#             */
/*   Updated: 2017/11/15 23:11:13 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (i == 0)
		return ((char*)s);
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j++;
	if (j < i)
	{
		i--;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
	}
	k = i - j + 1;
	if ((str = ft_strsub(s, j, k)) == NULL)
		return (NULL);
	str[i + 1] = '\0';
	return (str);
}
