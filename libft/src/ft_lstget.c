/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:46:40 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/28 12:32:45 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list		*ft_lstget(t_list *list, void *ct, size_t len,
		int (*cmp)(void*, size_t, void*, size_t))
{
	if (list)
	{
		while (list->next)
		{
			if ((*cmp)(ct, len, list->content, list->content_size) == 0)
				return (list);
			else
				list = list->next;
		}
	}
	return (NULL);
}
