/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:13:33 by cholm             #+#    #+#             */
/*   Updated: 2018/06/06 19:08:02 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include <limits.h>

# define BUFF_SIZE 60

typedef struct	s_vars
{
	int		i;
	int		end;
	int		read_val;
	char	readbuf[BUFF_SIZE + 1];
}				t_vars;

int				get_next_line(const int fd, char **line);

#endif
