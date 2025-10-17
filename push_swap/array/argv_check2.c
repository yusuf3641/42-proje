/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:55:01 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/12 14:52:45 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

static int	parse_sign(const char *s, int *i, int *sign)
{
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	return (1);
}

static int	parse_digits(const char *s, int *i, long *v, int sign)
{
	int	dig;

	dig = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		dig = 1;
		*v = *v * 10 + (s[*i] - '0');
		(*i)++;
		if ((sign == 1 && *v > INT_MAX)
			|| (sign == -1 && *v > (long)INT_MAX + 1))
			return (0);
	}
	return (dig);
}

int	ps_atoi_strict(const char *s, int *out)
{
	long	v;
	int		i;
	int		sign;
	int		dig;

	v = 0;
	i = 0;
	sign = 1;
	while (is_space(s[i]))
		i++;
	parse_sign(s, &i, &sign);
	dig = parse_digits(s, &i, &v, sign);
	if (dig == 0)
		return (0);
	while (is_space(s[i]))
		i++;
	if (s[i] != '\0')
		return (0);
	if (sign == -1)
		v = -v;
	if (v > INT_MAX || v < INT_MIN)
		return (0);
	*out = (int)v;
	return (1);
}

int	ps_has_dup(int *a, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (a[i] == a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
