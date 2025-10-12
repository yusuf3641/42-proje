/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:53:27 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/02 17:05:49 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sentences1;
	const unsigned char	*sentences2;
	size_t	i;

	i = 0;
	sentences1 = (const unsigned char *)s1;
	sentences2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (sentences1[i] != sentences2[i])
			return (sentences1[i] - sentences2[i]);
		i++;
		n--;
	}
	return (0);
}

