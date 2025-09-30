/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:34:11 by yuskaya           #+#    #+#             */
/*   Updated: 2025/07/05 16:56:36 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numlen(int n)
{
	int	len;

	len = (n <= 0);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*array;

	nb = n;
	len = ft_numlen(n);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	array[len] = '\0';
	if (nb < 0)
		nb = -nb;
	while (len--)
	{
		array[len] = (nb % 10) + '0';
		nb /= 10;
		if (nb == 0 && n < 0 && len == 0)
			array[0] = '-';
	}
	return (array);
}
 