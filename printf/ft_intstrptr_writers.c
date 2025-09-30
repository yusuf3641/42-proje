/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intstrptr_writers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:50:34 by yuskaya           #+#    #+#             */
/*   Updated: 2025/07/14 13:04:22 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_writer(char c)
{
	return (write(1, &c, 1));
}

int	ft_string_writer(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	if (write(1, str, ft_strlen(str)) == -1)
		return (-1);
	return (ft_strlen(str));
}

int	ft_pointer_writer(void *p)
{
	unsigned long	i;
	char			*a;
	char			buffer[40];
	int				index;
	int				counter;

	counter = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	i = (unsigned long)p;
	a = "0123456789abcdef";
	index = 0;
	while (i != 0)
	{
		buffer[index++] = a[i % 16];
		i /= 16;
	}
	counter = index;
	if (write(1, "0x", 2) == -1)
		return (-1);
	while (index > 0)
		if (ft_writer(buffer[--index]) == -1)
			return (-1);
	return (counter + 2);
}

int	ft_number_writer(int num)
{
	char	buffer[10];
	int		i;
	int		counter;
	long	a;

	a = num;
	i = 0;
	counter = 0;
	if (a == 0)
		return (write(1, "0", 1));
	if (a < 0)
	{
		counter += ft_writer('-');
		a = -a;
	}
	while (a > 0)
	{
		buffer[i++] = (a % 10) + '0';
		a /= 10;
	}
	counter += i;
	while (i > 0)
		ft_writer(buffer[--i]);
	return (counter);
}

int	ft_unsigned_writer(unsigned int number)
{
	char	letter;
	char	array[10];
	int		i;
	int		counter;

	if (number == 0)
		return (write(1, "0", 1));
	i = 0;
	while (number > 0)
	{
		letter = number % 10 + '0';
		array[i] = letter;
		number /= 10;
		i++;
	}
	counter = i;
	while (i > 0)
	{
		if (write(1, &array[--i], 1) == -1)
			return (-1);
	}
	return (counter);
}
