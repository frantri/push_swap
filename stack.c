/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 06:27:50 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/25 06:27:51 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stdlib.h>

int		push(t_stack *stack, int value)
{
	t_stack_elem	*newtop;

	if (!(newtop = new_stack_elem(value, stack->top, NULL)))
		return (exit_error(NOMEM, __LINE__));
	stack->top = newtop;
	if (stack->size == 0)
		stack->bottom = newtop;
	++stack->size;
	return (SUCCESS);
}

int		pop(t_stack *stack)
{
	int				res;
	t_stack_elem	*tmp;

	if (!stack || !stack->top)
		return (FAILURE);
	tmp = stack->top;
	res = tmp->value;
	del_stack_elem(&stack->top);
	--stack->size;
	return (res);
}

int		swap(t_stack *stack)
{
	int		tmp;

	if (!stack || stack->size < 2)
		return (FAILURE);
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
	return (SUCCESS);
}

int		rotate(t_stack *stack)
{
	t_stack_elem	*tmp_top;

	if (!stack || stack->size < 2)
		return (FAILURE);
	tmp_top = stack->top->next;
	stack->bottom->next = stack->top;
	stack->top->next = NULL;
	stack->top->prev = stack->bottom;
	stack->bottom = stack->top;
	stack->top = tmp_top;
	return (SUCCESS);
}

int		rotate_r(t_stack *stack)
{
	t_stack_elem	*tmp;

	if (!stack || stack->size < 2)
		return (FAILURE);
	tmp = stack->bottom->prev;
	tmp->next = NULL;
	stack->bottom->next = stack->top;
	stack->bottom->prev = NULL;
	stack->top->prev = stack->bottom;
	stack->bottom = tmp;
	stack->top = stack->top->prev;
	return (SUCCESS);
}
