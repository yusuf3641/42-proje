/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:51:23 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/11 16:45:42 by yuskaya          ###   ########.fr       */
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

void	init_and_fill_stack(t_stack *a, int *out, int *idx, int n)
{
	t_node	*node;
	int		i;

	i = 0;
	while (n > i)
	{
		node = node_new(out[i]);
		node->index = idx[i];
		push_back(a, node);
		i++;
	}
}

void	cleanup_resources(t_stack *a, t_stack *b, int *idx, int *out)
{
	stack_clear(a);
	stack_clear(b);
	free(idx);
	free(out);
}

int	init_data_and_validate(int argc, char **argv, int **out, int *n, int **idx)
{
	if (!ps_parse_args(argc, argv, out, n))
		return (put_error());
	if (main_helper(out, *n) == 0)
	{
		free(*out);
		return (0);
	}
	*idx = ps_make_indicates(*out, *n);
	if (!*idx)
	{
		free(*out);
		return (put_error());
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		*out;
	int		n;
	int		*idx;
	t_stack	*a;
	t_stack	*b;
	int		result;

	out = NULL;
	result = init_data_and_validate(argc, argv, &out, &n, &idx);
	if (result != 1)
		return (result);
	a = stack_init('a');
	b = stack_init('b');
	init_and_fill_stack(a, out, idx, n);
	if (n <= 5)
		small_sort(a, b);
	else
		bite_loop(a, b, n);
	cleanup_resources(a, b, idx, out);
	return (0);
}
