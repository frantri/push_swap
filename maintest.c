/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 06:25:33 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/25 06:26:07 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>
#include <libft.h>
#include <unistd.h>

int			g_count_opt = -1;
int			g_v_opt = 0;
int			g_interactive_opt = 0;

int			main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	int			i;

	i = 1;
	a = new_empty_stack();
	b = new_empty_stack();
	while (i < ac && check_opt(av[i]) == 0)
		i++;
	if (!av[i])
	{
		if (g_count_opt >= 0)
			ft_printf("Solved in %d operations\n", g_count_opt);
		exit(0);
	}
	if (check_args(av + i, &a) == -1)
		exit(1);
	if (g_interactive_opt)
		return (interactive_stack(&a, &b));
	sort_stack(&a, &b);
	if (g_count_opt >= 0)
		ft_printf("Solved in %d operations\n", g_count_opt);
	return (0);
}

int			interactive_stack(t_stack *a, t_stack *b)
{
	char		*line;

	ft_printf("{blue}INTERACTIVE MODE{eoc}\n");
	print_stacks(a, b);
	while ((!is_sort(a) || !empty(b)) &&
			get_next_line(STDOUT_FILENO, &line) == 1)
	{
		do_op(a, b, line);
		free(line);
		print_stacks(a, b);
	}
	if (g_count_opt >= 0 && is_sort(a))
		ft_printf("Solved in %d operations\n", g_count_opt);
	return (0);
}

int			check_opt(char *av)
{
	if (ft_strcmp("-i", av) == 0)
	{
		g_interactive_opt = 1;
		return (0);
	}
	else if (ft_strcmp("-c", av) == 0)
	{
		g_count_opt = 0;
		return (0);
	}
	else if (ft_strcmp("-v", av) == 0)
	{
		g_v_opt = 1;
		return (0);
	}
	else if (is_int(av))
		return (-1);
	else
	{
		ft_printf("Error: bad option: %s\n", av);
		exit(1);
	}
}
