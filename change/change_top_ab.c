/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_top_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:39:08 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/11 19:39:36 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_stack *a, t_stack *b)
{
	t_node	*n;

	if (!a || !b || b->size == 0)
		return ;
	n = pop_front(b);
	push_front(a, n);
	write(1, "pa\n", 3);
}

void	op_pb(t_stack *a, t_stack *b)
{
	t_node	*n;

	if (!a || a->size == 0)
		return ;
	n = pop_front(a);
	push_front(b, n);
	write(1, "pb\n", 3);
}
