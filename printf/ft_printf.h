/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:54:42 by yuskaya           #+#    #+#             */
/*   Updated: 2025/07/14 14:20:54 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int		ft_writer(char c);
int		ft_printf(const char *format, ...);
int		ft_letters_check(char c, va_list my_list);
int		ft_string_writer(char *str);
int		ft_pointer_writer(void *p);
int		ft_number_writer(int num);
int		ft_unsigned_writer(unsigned int number);
void	ft_hexadecimal_writer(unsigned int n, char c);
int		hexadecimal_counter(unsigned int i);
size_t	ft_strlen(const char *str);

#endif
