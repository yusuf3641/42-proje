/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:13:48 by yuskaya           #+#    #+#             */
/*   Updated: 2025/09/28 13:45:22 by yuskaya          ###   ########.fr       */
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
void	op_rrr(t_stack *a, t_stack *b)
{
	int okey;

	okey = 0;
	if (a && a->size >= 2)
	{
		okey = 1;
		rrotate_once(a);
	}
	if (b && b->size >= 2)
	{
		okey = 1;
		rrotate_once(b);
	}
	if (okey == 1)
		write(1, "rrr\n", 4);
}