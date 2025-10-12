/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:51:23 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/11 20:03:09 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

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

void	cleanup_resources(t_stack *a, t_stack *b, int *idx, int *out)
{
	stack_clear(a);
	stack_clear(b);
	free(idx);
	free(out);
}

int	init_data_and_validate(int argc, char **argv, int **out, t_data *data)
{
	if (!ps_parse_args(argc, argv, out, &data->n))
		return (put_error());
	if (main_helper(out, data->n) == 0)
	{
		free(*out);
		return (0);
	}
	data->idx = ps_make_indicates(*out, data->n);
	if (!data->idx)
	{
		free(*out);
		return (put_error());
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		*out;
	t_data	data;
	t_stack	*a;
	t_stack	*b;

	out = NULL;
	if (init_data_and_validate(argc, argv, &out, &data) != 1)
		return (0);
	a = stack_init('a');
	b = stack_init('b');
	init_and_fill_stack(a, out, data.idx, data.n);
	if (data.n <= 5)
		small_sort(a, b);
	else
		bite_loop(a, b, data.n);
	cleanup_resources(a, b, data.idx, out);
	return (0);
}
