/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:47:50 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/02 12:47:47 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	char *sentences;
	int i;

	sentences = (char *) s;
	i = ft_strlen(sentences) - 1;
	if ((char) c == '\0')
		return (char *) (s + i + 1);
	while (i >= 0)
	{
		if (s[i] == (char) c)
		{
			return (char *) (s + i);		
		}
		i--;
	}
	return NULL;
}
