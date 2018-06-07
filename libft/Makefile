# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cholm <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 09:35:48 by cholm             #+#    #+#              #
#    Updated: 2018/06/04 16:56:56 by cholm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	  ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_islower.c ft_isupper.c ft_strupcase.c ft_strlowcase.c ft_swap.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_isblank.c ft_itoa_upper.c ft_itoa_base_lower.c ft_flags.c ft_parse.c ft_precision.c ft_printf.c ft_printf_d.c ft_width.c ft_wchar.c ft_check_flags.c ft_printf_poux.c ft_print_pers.c ft_precisions_bis.c \
	  ft_printf_zero.c ft_call_opt.c ft_convert.c ft_printf_big_s.c \
	  get_next_line.c ft_sqrt.c ft_pow.c ft_free_tab.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	gcc -c -Wall -Wextra -Werror $<
$(NAME): 
	gcc -c -Wall -Wextra -Werror $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	
