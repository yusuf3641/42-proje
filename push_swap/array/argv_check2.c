/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:55:01 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/05 19:45:27 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>
#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

int	put_error(void)
{
	write(2, "Error\n", 6);
	return (0);
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
	dig = 0;
	while (is_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
		sign = (s[i++] == '-') ? -1 : 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		dig = 1;
		v = v * 10 + (s[i++] - '0');
		if ((sign == 1 && v > INT_MAX) || (sign == -1 && v < INT_MIN))
			return (0);
	}
	while ((is_space(s[i++])))
		if (!dig || s[i++] != '\0')
			return (0);
	*out = (int)(sign * v);
	return (1);
}
int	ps_has_dup(int *a, int n)
{
	int i;
	int j;

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