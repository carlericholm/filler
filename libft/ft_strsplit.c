/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:38:16 by cholm             #+#    #+#             */
/*   Updated: 2017/11/17 17:30:40 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count_words(char const *str, char c)
{
	int		i;
	int		sum_words;

	i = 0;
	sum_words = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 32 && str[i] <= 126 && str[i] != c) && (str[i + 1] == c
					|| str[i + 1] == '\0'))
			sum_words++;
		i++;
	}
	return (sum_words);
}

static int		ft_str_length(char const *str, int c, int *k)
{
	int i;

	i = 0;
	while (str[*k] == c)
		*k = *k + 1;
	while (str[*k] != c && str[*k] != '\0')
	{
		*k = *k + 1;
		i++;
	}
	*k = *k - i;
	return (i);
}

static char		**ft_much_line(char **tab, const char *s, char c, int i)
{
	int j;
	int k;
	int l;

	j = 0;
	k = 0;
	if (!(tab = (char **)malloc(sizeof(char **) * (ft_count_words(s, c) + 1))))
		return (NULL);
	tab[ft_count_words(s, c)] = 0;
	while (i < ft_count_words(s, c))
	{
		if (((s[j] == c && s[j - 1] != c) &&
					(s[j - 1] >= 32 && s[j - 1] <= 126)) || (s[j] == '\0'))
		{
			tab[i] = (char*)malloc(sizeof(char **) *
					(ft_str_length(s, c, &k) + 1));
			tab[i][ft_str_length(s, c, &k)] = '\0';
			l = 0;
			while (k < j)
				tab[i][l++] = s[k++];
			i++;
		}
		j++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	tab = NULL;
	if (!s)
		return (NULL);
	return (ft_much_line(tab, s, c, i));
}
