/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:25:27 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/02 15:19:51 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
 {
	const unsigned char *sentences;
	size_t	i;

	i = 0;
	sentences = (const unsigned char *) s;
	while (n > 0)
	{
		if (sentences[i] == (unsigned char) c)
		{
			return (void *) (sentences+ i);
		}
		i++;
		n--;
	}
	return (NULL);
 }
