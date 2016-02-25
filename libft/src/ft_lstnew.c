/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:28:06 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/27 16:13:05 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list*)malloc(sizeof(*new))))
	{
		if (content)
		{
			if ((new->content = malloc(content_size)))
			{
				ft_memcpy(new->content, content, content_size);
				new->content_size = content_size;
			}
			else
			{
				free(new);
				return (NULL);
			}
		}
		else
		{
			new->content_size = 0;
			new->content = NULL;
		}
		new->next = NULL;
	}
	return (new);
}
