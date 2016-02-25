/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 06:28:38 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/25 06:45:47 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SUCCESS 0
# define FAILURE 1
# define NOMEM 2
# define INVALID_OP 3
# include <string.h>

typedef struct			s_stack_elem
{
	int					value;
	struct s_stack_elem	*prev;
	struct s_stack_elem	*next;
}						t_stack_elem;

typedef struct			s_stack
{
	size_t				size;
	t_stack_elem		*top;
	t_stack_elem		*bottom;
}						t_stack;

typedef enum			e_opcode
{
	PA = 0,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	NONE
}						t_opcode;

typedef struct			s_op
{
	t_opcode			opcode;
	char				*op_upper;
	char				*op_lower;
}						t_op;

extern int				g_count_opt;
extern int				g_v_opt;
extern int				g_interactive_opt;
extern t_opcode			g_last_op;

int						exit_error(int	errcode, int line);
int						rotate_r(t_stack *stack);
int						rotate(t_stack *stack);
int						swap(t_stack *stack);
int						pop(t_stack *stack);
int						push(t_stack *stack, int value);
int						del_stack(t_stack *stack);
void					del_stack_elem(t_stack_elem **elem);
t_stack_elem			*new_stack_elem(int value, t_stack_elem *rest,
		t_stack_elem *prev);
t_stack					new_empty_stack(void);
t_stack_elem			*get_bottom(t_stack *stack);
void					print_stack(t_stack stack);
int						do_op(t_stack *a, t_stack *b, char *s);
t_opcode				get_op(char *s);
int						rotate_a_b(t_stack *a, t_stack *b, int rev);
int						swap_a_b(t_stack *a, t_stack *b);
int						empty(t_stack *stack);
int						is_sort(t_stack *stack);
void					print_stacks(t_stack *a, t_stack *b);
void					sort_stack(t_stack *a, t_stack *b);
int						has_dbl(t_stack *s);
int						is_int(char *arg);
int						check_args(char **av, t_stack *stack);
int						check_opt(char *av);
int						interactive_stack(t_stack *a, t_stack *b);
int						check_top(t_stack *a, t_stack *b);

int						check_last_push(t_stack *a, t_stack*b);
void					rot_to_min(t_stack *a, t_stack *b,
		int *min_max, int rev);
int						get_min_max(t_stack *stack, int *min, int *max);
int						check_min_max(int v, int *min, int *max);
#endif
