/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:53:13 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/12 20:19:50 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_all_tokens(char **argv)
{
	int	i;
	int	count;

	count = 0;
	i = 1;
	while (argv[i])
	{
		if (contains_space(argv[i]))
			count += ps_count_words(argv[i]);
		else if (argv[i][0] != '\0')
			count++;
		i++;
	}
	return (count);
}

int	ps_parse_args(char **argv, int **out, int *n)
{
	int	count;

	count = count_all_tokens(argv);
	if (count <= 0)
		return (1);
	*out = (int *)malloc(sizeof(int) * count);
	if (!*out)
		return (1);
	if (fill_all(argv, *out))
	{
		free(*out);
		*out = NULL;
		return (1);
	}
	*n = count;
	return (0);
}
