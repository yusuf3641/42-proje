/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 20:12:33 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/12 11:19:13 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ps_make_indicates(int *out, int n)
{
	int	*sorted;
	int	*idx;
	int	i;

	sorted = (int *)malloc(sizeof(int) * n);
	idx = (int *)malloc(sizeof(int) * n);
	if (!sorted || !idx)
	{
		free(sorted);
		free(idx);
		return (NULL);
	}
	ps_copy_ints(sorted, out, n);
	ps_sort_ints(sorted, n);
	i = 0;
	while_loop(out, sorted, idx, n);
	free(sorted);
	return (idx);
}
