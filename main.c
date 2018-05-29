/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:26:28 by cholm             #+#    #+#             */
/*   Updated: 2018/05/20 18:24:08 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	char *line;
	int fd;
	int ret;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		ft_putstr(line);
		ft_putstr("\n");
	}
	return (0);
}
