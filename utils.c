/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 06:26:54 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/27 00:33:56 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stdlib.h>

int		empty(t_stack *stack)
{
	return (stack->top == NULL);
}

int		exit_error(int errcode, int line)
{
	char	*msg;

	if (errcode == INVALID_OP)
		msg = "Invalid operation";
	else
		msg = "Unable to malloc";
	ft_dprintf(2, "%s at line %d\n", msg, line);
	exit(1);
}

int		is_sort(t_stack *stack)
{
	t_stack_elem	*it;

	if (empty(stack))
		return (1);
	it = stack->top;
	while (it->next)
	{
		if (it->next->value < it->value)
			return (0);
		it = it->next;
	}
	return (1);
}

int		get_min_max(t_stack *stack, int *min, int *max)
{
	int				res;
	t_stack_elem	*t;
	t_stack_elem	*b;

	t = stack->top;
	b = stack->bottom;
	*min = stack->top->value;
	*max = stack->top->value;
	while (42)
	{
		res = check_min_max(t->value, min, max) ? 1 : res;
		res = check_min_max(b->value, min, max) ? 0 : res;
		if (t == b || t->next == b)
			break ;
		t = t->next;
		b = b->prev;
	}
	return (res);
}

int		check_min_max(int v, int *min, int *max)
{
	if (v > *max)
		*max = v;
	if (v < *min)
		*min = v;
	if (*min == v)
		return (1);
	return (0);
}
