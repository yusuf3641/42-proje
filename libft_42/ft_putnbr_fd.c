/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:21:44 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/25 11:23:54 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr(int i, int fd)
{
	long	number;
	char	num;

	number = i;
	if (i < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	if (number >= 10)
	{
		ft_putnbr(number / 10, fd);
	}
	num = (number % 10) + '0';
	write(fd, &num, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
