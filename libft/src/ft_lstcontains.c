/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:10:24 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/28 16:52:21 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_lstcontains(t_list *list, void *ct, size_t len,
		int *(cmp)(void*, size_t, void*, size_t))
{
	if (list)
	{
		if ((*cmp)(ct, len, list->content, list->content_size) == 0)
			return (1);
		return (ft_lstcontains(list->next, ct, len, cmp));
	}
	while (list)
	{
		if ((*cmp)(ct, len, list->content, list->content_size) == 0)
			return (1);
		list = list->next;
	}
	return (0);
}
