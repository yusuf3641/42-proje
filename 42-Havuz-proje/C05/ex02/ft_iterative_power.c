/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:23:24 by yuskaya           #+#    #+#             */
/*   Updated: 2025/03/10 21:16:14 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if ((nb == 1 || power == 0) || (power == 0 && nb == 0))
		return (1);
	while (power-- > 0)
	{
		result *= nb;
	}
	return (result);
}
