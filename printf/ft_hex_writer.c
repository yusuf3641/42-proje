/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_writer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:12:01 by yuskaya           #+#    #+#             */
/*   Updated: 2025/07/14 13:09:12 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexadecimal_counter(unsigned int i)
{
	int	index;

	index = 0;
	while (i > 0)
	{
		i = i / 16;
		index++;
	}
	if (index == 0)
		index = 1;
	return (index);
}

void	ft_hexadecimal_writer(unsigned int n, char c)
{
	char	*hex_array;
	char	letter;
	int		i;

	i = 0;
	hex_array = "0123456789ABCDEF";
	if (c == 'x')
		hex_array = "0123456789abcdef";
	if (n >= 16)
	{
		ft_hexadecimal_writer(n / 16, c);
	}
	letter = hex_array[n % 16];
	ft_writer(letter);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
