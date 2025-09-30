/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:25:44 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/28 14:05:39 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	total;

	total = size * count;
	arr = malloc(total);
	if (!arr)
		return (NULL);
	ft_bzero(arr, total);
	return (arr);
}
