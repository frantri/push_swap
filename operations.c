/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 06:27:56 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/25 06:37:44 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

t_opcode	get_op(char *s)
{
	int				i;
	static t_op		data[] = {
		{PA, "PA", "pa"},
		{PB, "PB", "pb"},
		{SA, "SA", "sa"},
		{SB, "SB", "sb"},
		{SS, "SS", "ss"},
		{RA, "RA", "ra"},
		{RB, "RB", "rb"},
		{RR, "RR", "rr"},
		{RRA, "RRA", "rra"},
		{RRB, "RRB", "rrb"},
		{RRR, "RRR", "rrr"},
		{NONE, NULL, NULL}};

	i = 0;
	while (data[i].op_lower)
	{
		if (ft_strequ(data[i].op_lower, s) ||
				ft_strequ(data[i].op_upper, s))
			return (data[i].opcode);
		++i;
	}
	return (NONE);
}

static void	handle_opts(t_stack *a, t_stack *b, char *s)
{
	if (!g_interactive_opt)
	{
		ft_printf("%s", s);
		if (!is_sort(a) || !empty(b))
			ft_printf(" ");
		else
			ft_printf("\n");
	}
	if (g_count_opt >= 0)
		g_count_opt++;
	if (!g_interactive_opt && g_v_opt)
		print_stacks(a, b);
}

int			do_op(t_stack *a, t_stack *b, char *s)
{
	t_opcode	op;

	if ((op = get_op(s)) == NONE)
		return (FAILURE);
	op == SA ? swap(a) : (0);
	op == SB ? swap(b) : (0);
	op == SS ? swap_a_b(a, b) : (0);
	op == RA ? rotate(a) : (0);
	op == RB ? rotate(b) : (0);
	op == RR ? rotate_a_b(a, b, 0) : (0);
	op == RRA ? rotate_r(a) : (0);
	op == RRB ? rotate_r(b) : (0);
	op == RRR ? rotate_a_b(a, b, 1) : 0;
	if (op == PA && !empty(b))
		push(a, pop(b));
	if (op == PB && !empty(a))
		push(b, pop(a));
	handle_opts(a, b, s);
	return (SUCCESS);
}
