/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:18:58 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/12 11:19:12 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_copy_ints(int *dst, const int *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

void	ps_sort_ints(int *a, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i + 1 < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (a[j] < a[i])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	while_loop(int *vals, int *sorted, int *idx, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (sorted[j] == vals[i])
			{
				idx[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

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
