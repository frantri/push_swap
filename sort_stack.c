/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 06:27:08 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/25 06:46:03 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <stdlib.h>

void	sort_stack(t_stack *a, t_stack *b)
{
	int		min_max[2];

	if (g_v_opt)
		print_stacks(a, b);
	while (!check_top(a, b) || !check_last_push(a, b) || !empty(b))
	{
		if (get_min_max(a, min_max, min_max + 1) == 1)
			rot_to_min(a, b, min_max, 0);
		else
			rot_to_min(a, b, min_max, 1);
	}
}

int		check_top(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && a->size <= 10 &&
			a->top->value > a->top->next->value)
	{
		do_op(a, b, "sa");
	}
	return (1);
}

int		check_last_push(t_stack *a, t_stack *b)
{
	int		min_max[2];

	if (is_sort(a))
	{
		while (!empty(b))
			do_op(a, b, "pa");
		get_min_max(a, min_max, min_max + 1);
		while (a->top->value != min_max[0])
			do_op(a, b, "ra");
	}
	else
		return (0);
	return (1);
}

void	rot_to_min(t_stack *a, t_stack *b, int *min_max, int rev)
{
	while (a->top->value != min_max[0])
	{
		if (a->top->value == min_max[1])
		{
			do_op(a, b, "pb");
			if (rev == 0)
				do_op(a, b, "rr");
			else
				do_op(a, b, "rb");
			min_max[1]--;
		}
		if (a->top && a->top->value == min_max[1])
			continue ;
		if (rev == 1)
			do_op(a, b, "rra");
		else if (rev == 0)
			do_op(a, b, "ra");
		if (rev == -1)
			rev = 0;
	}
	if (is_sort(a))
		return ;
	do_op(a, b, "pb");
}
