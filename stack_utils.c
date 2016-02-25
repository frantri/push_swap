/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 06:26:52 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/25 06:26:53 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stdlib.h>

t_stack_elem	*get_bottom(t_stack *stack)
{
	t_stack_elem	*it;

	it = stack->top;
	while (it && it->next)
		it = it->next;
	return (it);
}

t_stack			new_empty_stack(void)
{
	t_stack	res;

	ft_bzero(&res, sizeof(res));
	return (res);
}

t_stack_elem	*new_stack_elem(int value, t_stack_elem *next,
		t_stack_elem *prev)
{
	t_stack_elem *res;

	if (!(res = (t_stack_elem *)ft_memalloc(sizeof(*res))))
		return (NULL);
	res->value = value;
	res->next = next;
	res->prev = prev;
	if (next)
		next->prev = res;
	if (prev)
		prev->next = res;
	return (res);
}

void			del_stack_elem(t_stack_elem **elem)
{
	t_stack_elem	*next;

	next = (*elem)->next;
	free(*elem);
	if (next)
		next->prev = NULL;
	*elem = next;
}

int				del_stack(t_stack *stack)
{
	if (!stack)
		return (FAILURE);
	while (stack->top)
		del_stack_elem(&stack->top);
	return (SUCCESS);
}
