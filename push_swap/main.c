/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:51:23 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/05 20:11:07 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main_helper(int **out, int n)
{
	if (n == 0)
		return (0);
	if (ps_has_dup(*out, n))
		return (put_error());
	if (ps_is_sorted(*out, n))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		*out;
	int		n;
	int		*idx;
	t_stack	*a;
	t_stack	*b;
	t_node	*node;
	int		i;

	i = 0;
	out = NULL;
	if (!ps_parse_args(argc, argv, &out, &n))
		return (put_error());
	if (main_helper(&out, n) == 0)
	{
		free(out);
		return (0);
	}
	idx = ps_make_indicates(out, n);
	if (!idx)
	{
		free(out);
		return (put_error());
	}
	a = stack_init('a');
	b = stack_init('b');
	while (n > i)
	{
		node = node_new(out[i]);
		node->index = idx[i];
		push_back(a, node);
		i++;
	}
	if (n <= 5)
		small_sort(a, b);
	else
		bite_loop(a, b, n);
	stack_clear(a);
	stack_clear(b);
	free(idx);
	free(out);
	return (0);
}
