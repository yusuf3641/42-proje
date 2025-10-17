/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:00:00 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/13 00:00:00 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contains_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	fill_from_split(char **words, int *dst, int *k)
{
	int	v;
	int	i;

	i = 0;
	while (words[i])
	{
		if (!ps_atoi_strict(words[i], &v))
			return (1);
		dst[*k] = v;
		*k += 1;
		i++;
	}
	return (0);
}

static int	handle_arg(char *arg, int *out, int *k)
{
	char	**words;
	int		count;
	int		value;

	if (contains_space(arg))
	{
		count = ps_count_words(arg);
		words = ps_split(arg, ' ');
		if (!words || fill_from_split(words, out, k))
		{
			if (words)
				ps_free_split(words, count);
			return (1);
		}
		ps_free_split(words, count);
		return (0);
	}
	if (!ps_atoi_strict(arg, &value))
		return (1);
	out[(*k)++] = value;
	return (0);
}

int	fill_all(char **argv, int *out)
{
	int	k;
	int	i;

	k = 0;
	i = 1;
	while (argv[i])
	{
		if (handle_arg(argv[i], out, &k))
			return (1);
		i++;
	}
	return (0);
}
