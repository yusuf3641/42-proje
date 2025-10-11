/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up_down_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:00:00 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/11 18:47:24 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_once(t_stack *s)
{
	t_node	*n;

	if (!s || s->size < 2)
		return ;
	n = pop_front(s);
	push_back(s, n);
}
void	op_ra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	rotate_once(a);
	write(1, "ra\n", 3);
}
void	op_rb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	rotate_once(b);
	write(1, "rb\n", 3);
}
