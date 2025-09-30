/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:37:03 by yuskaya           #+#    #+#             */
/*   Updated: 2025/09/07 21:30:39 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	word_length(char **sentences, char c)
{
	int	len;

	len = 0;
	while (**sentences && **sentences == c)
		(*sentences)++;
	while (**sentences && **sentences != c)
	{
		len++;
		(*sentences)++;
	}
	return (len);
}

static int	words(char const *s, char c)
{
	int	i;
	int	counter;
	int	in_word;

	i = 0;
	counter = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			counter++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (counter);
}

static char	*copy_word(char *s, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	*copy;
	char	*start;
	char	**array;
	int		i;
	int		len;

	(void)c;
	i = 0;
	copy = ft_strdup(s);
	if (!copy)
		return (NULL);
	start = copy;
	array = (char **)malloc((words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (free(copy), NULL);
	while (i < words(s, c))
	{
		len = word_length(&copy, c);
		array[i] = copy_word(copy - len, len);
		if (!array[i++])
			return (free(start), NULL);
	}
	array[i] = NULL;
	return (free(start), array);
}
