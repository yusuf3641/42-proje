/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:10:09 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/02 11:37:27 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	char	letter;

	letter = (char) c;
	if ('A' <= letter && letter <= 'Z')
		return (letter + 32);
	return letter;
}
