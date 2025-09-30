/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:49:22 by yuskaya           #+#    #+#             */
/*   Updated: 2025/03/08 09:44:58 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *dest)
{
	int	counter;

	counter = 0;
	while (*dest)
	{
		counter++;
		dest++;
	}
	return (counter);
}

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	i = 0;
	len = str_len(dest);
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
