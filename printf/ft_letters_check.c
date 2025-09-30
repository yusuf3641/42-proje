/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letters_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:48:01 by yuskaya           #+#    #+#             */
/*   Updated: 2025/07/13 19:14:13 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_letters_check(char c, va_list my_list)
{
	unsigned int	i;

	if (c == 'c')
		return (ft_writer(va_arg(my_list, int)));
	else if (c == 's')
		return (ft_string_writer(va_arg(my_list, char *)));
	else if (c == 'p')
		return (ft_pointer_writer(va_arg(my_list, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_number_writer(va_arg(my_list, int)));
	else if (c == 'u')
		return (ft_unsigned_writer(va_arg(my_list, unsigned int)));
	else if (c == 'x' || c == 'X')
	{
		i = va_arg(my_list, unsigned int);
		ft_hexadecimal_writer(i, c);
		return (hexadecimal_counter(i));
	}
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (ft_writer(c));
}
