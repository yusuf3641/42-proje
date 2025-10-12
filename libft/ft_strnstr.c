/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:18:19 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/02 18:20:09 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (len > i){
		if (haystack[i] == needle[0])
		{	
			while (len > i){
				if (haystack[i] != needle[j])
					return (NULL); 
				i++;
				j++;	
			}
			if ( < ft_strlen((char *) needle))
				return (NULL);
			return (char *) haystack + i - j;
		}
		i++;
	}
	return (NULL);
}

#include <stdio.h>
int main(){
	char *i = ft_strnstr("selam millet", "lam", 5);
	printf("%s", i);
}