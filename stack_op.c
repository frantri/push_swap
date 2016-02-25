/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 06:28:23 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/25 06:28:24 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int		rotate_a_b(t_stack *a, t_stack *b, int rev)
{
	if (rev)
	{
		rotate_r(a);
		rotate_r(b);
	}
	else
	{
		rotate(a);
		rotate(b);
	}
	return (SUCCESS);
}

int		swap_a_b(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	return (SUCCESS);
}

int		has_dbl(t_stack *s)
{
	t_stack_elem	*tmp;
	t_stack_elem	*it;

	tmp = s->top;
	while (tmp)
	{
		it = tmp->next;
		while (it)
		{
			if (it->value == tmp->value)
				return (1);
			it = it->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_stack_elem	*it_a;
	t_stack_elem	*it_b;

	it_a = a ? a->top : NULL;
	it_b = b ? b->top : NULL;
	ft_printf("\n=================\n");
	ft_printf("%-10s | %-10s\n\n", "A", "B");
	while (it_a || it_b)
	{
		if (it_a && it_b)
			ft_printf("%-10d | %-10d\n", it_a->value, it_b->value);
		else if (it_a)
			ft_printf("%-10d | %10s\n", it_a->value, " ");
		else if (it_b)
			ft_printf("%10s | %-10d\n", " ", it_b->value);
		if (it_a)
			it_a = it_a->next;
		if (it_b)
			it_b = it_b->next;
	}
	ft_printf("=================\n");
}
