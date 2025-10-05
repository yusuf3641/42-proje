/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_top_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:39:08 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/05 11:37:09 by yuskaya          ###   ########.fr       */
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
void	set_index(t_stack *a)
{
	t_node *cur;
	t_node *cmp;
	int idx;

	cur = a->up;
	while (cur)
	{
		idx = 0;
		cmp = a->up;
		while (cmp)
		{
			if (cmp->value < cur->value)
				idx++;
			cmp = cmp->next;
		}
		cur->index = idx;
		cur = cur->next;
	}
}