/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:45:08 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/02 11:37:31 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	char	letter;

	letter = (char) c;
	if ('a' <= letter && letter <= 'z')
		letter -= 32;
	return (letter);
}