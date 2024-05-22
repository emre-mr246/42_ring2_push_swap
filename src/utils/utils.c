/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:43:58 by emgul             #+#    #+#             */
/*   Updated: 2024/05/22 12:16:08 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../lib/libft/libft.h"

/**
 * @brief Converts a string to a long integer.
 *
 * @param str The string to be converted.
 * @return The converted long integer value.
 */
long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (!str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

/**
 * @brief Calculates the size of a null-terminated array of strings.
 *
 * @param input The array of strings (null-terminated)
 *  whose size is to be calculated.
 * @return The number of strings in the array
 *  (excluding the NULL terminator).
 */
int	str_arr_size(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}
