/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 06:27:54 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/25 06:27:54 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int		is_int(char *arg)
{
	int			i;
	intmax_t	v;

	i = 0;
	if (arg[0] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	v = ft_atoi(arg);
	if (v != (int)v)
		return (0);
	return (1);
}

int		check_args(char **av, t_stack *stack)
{
	int		i;

	i = 0;
	while (av[i])
		++i;
	i--;
	while (i >= 0)
	{
		if (!is_int(av[i]))
		{
			ft_dprintf(2, "Error: not a int: %s\n", av[i]);
			return (-1);
		}
		push(stack, ft_atoi(av[i]));
		i--;
	}
	if (has_dbl(stack))
	{
		ft_dprintf(2, "Error: some numbers are duplicated\n");
		return (-1);
	}
	return (0);
}
