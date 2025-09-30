/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <kullaniciAdi@student.42kocaeli.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:13:21 by yuskaya           #+#    #+#             */
/*   Updated: 2025/03/02 16:07:43 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	changer;

	changer = 0;
	i = 0;
	j = size;
	while (size > i)
	{
		j = i + 1;
		while (j > 0)
		{
			if (tab[i] > tab[j])
			{
				changer = tab[i];
				tab[i] = tab[j];
				tab[j] = changer;
			}
			j++;
		}
		i++;
	}
}
