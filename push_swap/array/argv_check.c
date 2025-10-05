/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:53:13 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/05 19:45:11 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

int	ps_is_sorted(int *a, int n)
{
	int	i;

	i = 0;
	while (i + 1 < n)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
int	ps_parse_args(int argc, char **argv, int **out, int *n)
{
	int i;
	int x;
	int *a;

	*n = argc - 1;
	if (*n <= 0)
	{
		*out = NULL;
		return (1);
	}
	a = (int *)(malloc(sizeof(int) * (*n)));
	if (!a)
		return (0);
	i = 0;
	while (i < *n)
	{
		if (!ps_atoi_strict(argv[i + 1], &x))
		{
			free(a);
			return (0);
		}
		a[i++] = x;
	}
	*out = a;
	return (1);
}