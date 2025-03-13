/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <kullaniciAdi@student.42kocaeli.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:45:55 by yuskaya           #+#    #+#             */
/*   Updated: 2025/03/02 08:05:49 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	changer;
	int	counter;

	counter = 0;
	i = 0;
	j = 0;
	if (size % 2 != 0)
		counter = (size / 2) + 1;
	else
		counter = size / 2;
	while (i < counter)
	{
		changer = tab[i];
		tab[i] = tab[size - i -1];
		tab[size - i - 1] = changer;
		i++;
	}
}
