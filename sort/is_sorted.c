/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:18:36 by yuskaya           #+#    #+#             */
/*   Updated: 2025/09/30 11:52:40 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (!a || a->size < 2)
		return (1);
	cur = a->up;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
void	sort_two(t_stack *a)
{
	t_node	*s;

	if (!a || a->size < 2)
		return ;
	s = a->up;
	if (s->value > s->next->value)
		op_sa(a);
}
void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	if (!a || a->size < 2 || is_sorted(a))
		return ;
	if (a->size == 2)
		return (sort_two(a));
	x = a->up->value;
	y = a->up->next->value;
	z = a->up->next->next->value;
	if (x > y && y < z && x < z)
		op_sa(a);
	else if (x > y && y > z)
	{
		op_sa(a);
		op_rra(a);
	}
	else if (x > y && y < z && x > z)
		op_ra(a);
	else if (x < y && y > z && x < z)
		sort_help_three(a);
	else if (x < y && y > z && x > z)
		op_rra(a);
}

void	sort_help_three(t_stack *a)
{
	op_sa(a);
	op_ra(a);
}
