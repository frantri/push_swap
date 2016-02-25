/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:32:00 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/28 09:21:33 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddcmp(t_list **list, t_list *new,
		int (*cmp)(void*, size_t, void*, size_t))
{
	t_list	*it;

	if (list)
	{
		if (*list == NULL ||
				(*cmp)(new->content, new->content_size,
					(*list)->content, (*list)->content_size) < 0)
		{
			new->next = *list;
			*list = new;
			return ;
		}
		it = *list;
		while (it->next &&
				(*cmp)(new->content, new->content_size,
					it->next->content, it->next->content_size) >= 0)
			it = it->next;
		new->next = it->next;
		it->next = new;
	}
}
