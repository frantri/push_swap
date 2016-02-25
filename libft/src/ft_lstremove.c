/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:36:01 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/28 09:21:10 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list		*ft_lstremove(t_list **list, void *ct, size_t len,
		int (*cmp)(void*, size_t, void*, size_t))
{
	t_list	*it;
	t_list	*del;

	if (list && *list)
	{
		it = *list;
		if ((*cmp)(it->content, it->content_size, ct, len) == 0)
		{
			*list = (*list)->next;
			return (it);
		}
		while (it->next &&
				(*cmp)(it->next->content,
					it->next->content_size, ct, len) != 0)
			it = it->next;
		if (it->next == NULL)
			return (NULL);
		del = it->next;
		it->next = it->next->next;
		del->next = NULL;
		return (del);
	}
	return (NULL);
}
