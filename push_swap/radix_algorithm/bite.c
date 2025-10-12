/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bite.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 15:02:46 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/11 19:39:53 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int n)
{
	int	bits;
	int	max;

	bits = 0;
	if (n <= 1)
		return (1);
	max = n - 1;
	while (0 < max)
	{
		bits++;
		max = max >> 1;
	}
	return (bits);
}

void	bite_loop(t_stack *a, t_stack *b, int n)
{
	int	max_bite;
	int	idx;
	int	bit;
	int	cnt;

	bit = 0;
	max_bite = max_bits(n);
	while (max_bite > bit)
	{
		cnt = 0;
		while (n > cnt)
		{
			idx = a->up->index;
			if ((idx >> bit & 1) == 0)
				op_pb(a, b);
			else
				op_ra(a);
			cnt++;
		}
		while (b->size > 0)
			op_pa(a, b);
		bit++;
	}
}
