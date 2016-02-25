/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:29:39 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/27 15:09:40 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*it;

	if (!alst)
		return ;
	if (*alst)
	{
		it = *alst;
		while (it->next)
			it = it->next;
		it->next = new;
	}
	else
		*alst = new;
}
