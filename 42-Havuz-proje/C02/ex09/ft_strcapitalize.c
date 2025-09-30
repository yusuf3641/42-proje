/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <kullaniciAdi@student.42kocaeli.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:02:35 by yuskaya           #+#    #+#             */
/*   Updated: 2025/03/08 00:46:34 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	prev_non_alnum;

	i = 0;
	prev_non_alnum = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if (prev_non_alnum && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		if ((str[i] < '0' || (str[i] > '9' && str[i] < 'A'))
			|| (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			prev_non_alnum = 1;
		else
			prev_non_alnum = 0;
		i++;
	}
	return (str);
}
