/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:24:12 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/25 14:03:05 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*pass_space(const char *str)
{
	while (*str == ' ' || *str == '\r' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\v')
		str++;
	return ((char *)str);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		mark;

	result = 0;
	mark = 1;
	str = pass_space(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mark = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = (10 * result) + (*str - '0');
		else
			break ;
		str++;
	}
	return (mark * result);
}
