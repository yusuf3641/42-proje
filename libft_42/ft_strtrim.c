/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:07:17 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/26 19:07:12 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	for_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		i++;
	}
	return (i);
}

static int	for_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*arr;

	if (!s1 || !set)
		return (NULL);
	start = for_start(s1, set);
	end = for_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	len = end - start + 1;
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s1 + start, len + 1);
	return (arr);
}
