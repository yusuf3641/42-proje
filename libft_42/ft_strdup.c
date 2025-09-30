/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:23:15 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/26 13:56:18 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*array;

	i = 0;
	len = ft_strlen(s);
	array = (char *)malloc((len + 1) * sizeof(char));
	if (!array)
		return (NULL);
	while (i < len)
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
