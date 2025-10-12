/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 20:12:27 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/12 11:19:14 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ps_skip_delimiters(char *str, int *i, char c)
{
	while (str[*i] && (str[*i] == c || str[*i] == '\t' || str[*i] == '\n'))
		(*i)++;
}

void	ps_skip_word(char *str, int *i, char c)
{
	while (str[*i] && str[*i] != c && str[*i] != '\t' && str[*i] != '\n')
		(*i)++;
}

int	ps_next_word(char *str, char **out, int *i, char c)
{
	int	start;

	ps_skip_delimiters(str, i, c);
	start = *i;
	ps_skip_word(str, i, c);
	*out = ps_allocate_word(str, start, *i);
	if (!*out)
		return (0);
	return (1);
}

char	**ps_split(char *str, char c)
{
	char	**result;
	int		words;
	int		i;
	int		j;

	words = ps_count_words(str);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		if (!ps_next_word(str, &result[j], &i, c))
		{
			ps_free_partial_result(result, j);
			return (NULL);
		}
		j++;
	}
	result[j] = NULL;
	return (result);
}
