/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:16 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/05 19:31:41 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_up(t_stack *a, int min)
{
	int	pos;
	int	size;

	if (!a || a->size == 0)
		return ;
	if (a->up && a->up->value == min)
		return ;
	size = a->size;
	pos = find_pos(a, min);
	if (pos <= size / 2)
		while (a->up->value != min)
			op_ra(a);
	else
		while (a->up->value != min)
			op_rra(a);
}

void	sort_four_five(t_stack *a, t_stack *b)
{
	int	min;

	if (!a || !b)
		return ;
	if (a->size <= 3 || is_sorted(a))
		return ;
	while (a->size > 3)
	{
		min = get_min_value(a);
		get_min_up(a, min);
		op_pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		op_pa(a, b);
}

int	get_min_value(t_stack *stack)
{
	t_node	*temp;
	int		min;

	if (!stack || !stack->up)
		return (0);
	temp = stack->up;
	min = temp->value;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int	find_pos(t_stack *a, int min)
{
	t_node	*s;
	int		pos;

	s = a->up;
	pos = 0;
	while (s && s->value != min)
	{
		s = s->next;
		pos++;
	}
	return (pos);
}
void	small_sort(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 1 || is_sorted(a))
		return ;
	if (a->size == 2)
	{
		sort_two(a);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	if (a->size == 4 || a->size == 5)
	{
		if (!b)
			return ;
		sort_four_five(a, b);
		return ;
	}
}
