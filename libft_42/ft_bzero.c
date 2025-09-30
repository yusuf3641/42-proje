/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:27:35 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/18 14:54:56 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*sentences;
	size_t			i;

	i = 0;
	sentences = (unsigned char *)s;
	while (i < n)
	{
		sentences[i] = '\0';
		i++;
	}
}
