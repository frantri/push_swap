/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:32:44 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/28 16:48:42 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgeti(t_list *list, int i)
{
	if (i == 0)
		return (list);
	if (list == NULL)
		return (NULL);
	while (i > 0 && list)
	{
		list = list->next;
		i--;
	}
	return (list);
}
