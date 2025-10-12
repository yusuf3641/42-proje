/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:53:13 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/12 20:17:05 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_parse_array(char **argv, int count, int **out)
{
	int	*a;
	int	i;
	int	x;

	a = malloc(sizeof(int) * count);
	if (!a)
		return (1);
	i = 0;
	while (i < count)
	{
		if (!ps_atoi_strict(argv[i], &x))
		{
			free(a);
			return (1);
		}
		a[i++] = x;
	}
	*out = a;
	return (i);
}

int	ps_parse_args(char **argv, int **out, int *n)
{
	int	i;
	int	j;
	int	control;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ' || argv[i][j] == '\t' || argv[i][j] == '\n')
				control = 1;
			j++;
		}
		if (control == 1)
			ps_parse_string(argv[i], out, n);
		else
			*n += ps_parse_array(argv[i], *n, out);
		i++;
	}
	if (*n <= 0)
	{
		*out = NULL;
		return (1);
	}
	return (*n);
}

int	ps_parse_string(char *str, int **out, int *n)
{
	char	**words;
	int		result;

	*n = ps_count_words(str);
	if (*n <= 0)
	{
		*out = NULL;
		return (1);
	}
	words = ps_split(str, ' ');
	if (!words)
		return (1);
	result = ps_parse_array(words, *n, out);
	ps_free_split(words, *n);
	return (result);
}
