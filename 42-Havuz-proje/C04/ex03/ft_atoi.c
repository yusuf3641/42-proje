/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:28:20 by yuskaya           #+#    #+#             */
/*   Updated: 2025/03/10 13:38:50 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	counter_result(int array_counter, int *my_keeper)
{
	int	counters[3];
	int	i;
	int	result;

	result = 0;
	i = 0;
	counters[0] = 0;
	counters[1] = 0;
	counters[2] = 1;
	while (array_counter > 0)
	{
		counters[1] = array_counter - 1;
		while (counters[1] > 0)
		{
			counters[2] *= 10;
			counters[1]--;
		}
		result += (counters[2] * my_keeper[i]);
		counters[2] = 1;
		array_counter--;
		i++;
	}
	return (result);
}

char	*delete_space(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int	number;
	int	array_counter;
	int	my_keeper[10];

	array_counter = 0;
	number = 1;
	str = delete_space(str);
	while (*str != '\0')
	{
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				number *= -1;
		}
		else if (*str <= '9' && *str >= '0')
		{
			my_keeper[array_counter] = *str - '0';
			array_counter++;
		}
		else
			break ;
		str++;
	}
	return (counter_result(array_counter, my_keeper) * number);
}
