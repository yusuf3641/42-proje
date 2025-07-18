/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:27:41 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/02 11:36:42 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*sentences;

	i = 0;
	sentences = (unsigned char *)b;
	while (i < len)
	{
		sentences[i] = (unsigned char)c;
		i++;
	}
	return (b);
}