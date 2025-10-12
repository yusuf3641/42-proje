/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_top2_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:03:59 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/11 19:39:25 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top2(t_stack *s)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!s || s->size < 2)
		return ;
	first = s->up;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	else
		s->last = first;
	s->up = second;
}

void	op_sa(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	swap_top2(a);
	write(1, "sa\n", 3);
}

void	op_sb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	swap_top2(b);
	write(1, "sb\n", 3);
}
