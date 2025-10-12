/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:13:48 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/11 19:38:37 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_once(t_stack *s)
{
	t_node	*n;

	if (!s || s->size < 2)
		return ;
	n = pop_back(s);
	push_front(s, n);
}

void	op_rra(t_stack *a)
{
	t_node	*n;

	if (!a || a->size < 2)
		return ;
	n = pop_back(a);
	push_front(a, n);
	write(1, "rra\n", 4);
}

void	op_rrb(t_stack *b)
{
	t_node	*n;

	if (!b || b->size < 2)
		return ;
	n = pop_back(b);
	push_front(b, n);
	write(1, "rrb\n", 4);
}
