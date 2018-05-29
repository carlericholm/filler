/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:08:43 by cholm             #+#    #+#             */
/*   Updated: 2017/11/20 19:41:12 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *first;

	if (!(new = ft_lstnew((*f)(lst)->content, (*f)(lst)->content_size)))
		return (NULL);
	first = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = ft_lstnew((*f)(lst)->content,
			(*f)(lst)->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
