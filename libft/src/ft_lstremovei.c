/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:04:31 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/28 14:41:39 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstremovei(t_list **list, int i)
{
	t_list	*it;
	t_list	*trm;

	if (i < 0)
		return (NULL);
	if (list == NULL || *list == NULL)
		return (NULL);
	it = *list;
	if (i == 0)
	{
		*list = (*list)->next;
		it->next = NULL;
		return (it);
	}
	while (i-- > 1 && it->next)
		it = it->next;
	if (it->next)
	{
		trm = it->next;
		it->next = it->next->next;
		trm->next = NULL;
		return (trm);
	}
	return (NULL);
}
