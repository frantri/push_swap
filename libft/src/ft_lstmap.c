/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:02:37 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/27 15:06:18 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_del(void *ptr, size_t len)
{
	len++;
	free(ptr);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*l;

	new = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		l = (*f)(lst);
		if (l)
			ft_lstadd_back(&new, l);
		else
		{
			ft_lstdel(&new, &ft_del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new);
}
