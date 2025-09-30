/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:02:38 by yuskaya           #+#    #+#             */
/*   Updated: 2025/07/13 19:14:12 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	my_list;
	int		i;
	int		count;
	int		tmp;

	if (!format)
		return (-1);
	va_start(my_list, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			tmp = ft_letters_check(format[++i], my_list);
		else
			tmp = ft_writer(format[i]);
		if (tmp == -1)
			return (va_end(my_list), -1);
		count += tmp;
		i++;
	}
	va_end(my_list);
	return (count);
}
