/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:12:41 by yuskaya           #+#    #+#             */
/*   Updated: 2025/03/08 00:52:28 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;
	char			*hex_digit;

	hex_digit = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if (c < 32 || c == 127)
		{
			write(1, "\\", 1);
			write(1, &hex_digit[c / 16], 1);
			write(1, &hex_digit[c % 16], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
