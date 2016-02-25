/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrmdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:06:18 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/28 12:48:09 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static void		ft_delelem(void *content, size_t content_size)
{
	if (content)
		free(content);
	content_size++;
}

void			ft_lstrmdel(t_list **list, void *ct, size_t len,
		int (*cmp)(void*, size_t, void*, size_t))
{
	t_list	*elem;

	elem = ft_lstremove(list, ct, len, cmp);
	if (elem)
		ft_lstdelone(&elem, &ft_delelem);
}
