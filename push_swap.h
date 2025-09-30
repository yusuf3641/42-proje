/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:37:12 by yuskaya           #+#    #+#             */
/*   Updated: 2025/09/30 11:45:17 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;

}					t_node;

typedef struct s_stack
{
	char			name;
	int				size;
	t_node			*up;
	t_node			*last;
}					t_stack;

t_node				*node_new(int value);
t_stack				*stack_init(char name);
void				stack_clear(t_stack *s);

void				push_front(t_stack *s, t_node *n);
t_node				*pop_front(t_stack *s);
void				push_back(t_stack *s, t_node *n);
t_node				*pop_back(t_stack *s);

void				swap_top2(t_stack *s);
void				op_sa(t_stack *a);
void				op_sb(t_stack *b);
void				op_ss(t_stack *a, t_stack *b);

void				op_pa(t_stack *a, t_stack *b);
void				op_pb(t_stack *a, t_stack *b);

void				rotate_once(t_stack *s);
void				op_rr(t_stack *a, t_stack *b);

void				op_ra(t_stack *a);
void				op_rb(t_stack *b);

void				rrotate_once(t_stack *s);
void				op_rra(t_stack *a);
void				op_rrb(t_stack *b);
void				op_rrr(t_stack *a, t_stack *b);

int					is_sorted(t_stack *a);
void				sort_two(t_stack *a);
void				sort_three(t_stack *a);
void				sort_help_three(t_stack *a);
void				sort_four_five(t_stack *a, t_stack *b);
void				small_sort(t_stack *a, t_stack *b);

#endif