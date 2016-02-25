/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:54:55 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/28 11:26:21 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*cur;
	t_list	*next;

	if (alst && *alst)
	{
		cur = *alst;
		while (cur->next)
		{
			next = cur->next;
			(*del)(cur->content, cur->content_size);
			free(cur);
			cur = next;
		}
		(*del)(cur->content, cur->content_size);
		free(cur);
		*alst = NULL;
	}
}
