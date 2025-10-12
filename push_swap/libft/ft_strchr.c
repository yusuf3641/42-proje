/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:15:15 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/02 11:36:52 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strchr(const char *s, int c)
{
	if ((char)c == '\0')
		return (char *)s;
	while (*s){
		if (*s == c){
			return  (char *)s;
		}
		s++;
	}
	return NULL;
}
