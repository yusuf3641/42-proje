/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:53:13 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/11 18:49:21 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ps_split(char *str, char c)
{
	char	**result;
	int		words;
	int		i;
	int		j;
	int		start;

	words = ps_count_words(str);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		while (str[i] && (str[i] == c || str[i] == '\t' || str[i] == '\n'))
			i++;
		start = i;
		while (str[i] && str[i] != c && str[i] != '\t' && str[i] != '\n')
			i++;
		result[j] = ps_allocate_word(str, start, i);
		if (!result[j])
		{
			ps_free_partial_result(result, j);
			return (NULL);
		}
		j++;
	}
	result[j] = NULL;
	return (result);
}

static int	ps_parse_array(char **argv, int count, int **out)
{
	int	*a;
	int	i;
	int	x;

	a = malloc(sizeof(int) * count);
	if (!a)
		return (0);
	i = 0;
	while (i < count)
	{
		if (!ps_atoi_strict(argv[i], &x))
		{
			free(a);
			return (0);
		}
		a[i++] = x;
	}
	*out = a;
	return (1);
}

int	ps_parse_args(int argc, char **argv, int **out, int *n)
{
	if (argc == 2)
		return (ps_parse_string(argv[1], out, n));
	*n = argc - 1;
	if (*n <= 0)
	{
		*out = NULL;
		return (1);
	}
	return (ps_parse_array(argv + 1, *n, out));
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
		return (0);
	result = ps_parse_array(words, *n, out);
	ps_free_split(words, *n);
	return (result);
}
