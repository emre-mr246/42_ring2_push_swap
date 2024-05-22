/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:43:25 by emgul             #+#    #+#             */
/*   Updated: 2024/05/22 12:10:48 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../lib/libft/libft.h"

/**
 * @brief Prints an error message to the standard error output
 *  and exits the program with an error code.
 *
 * @param message The error message to be printed.
 * @return This function does not return as it terminates the program.
 */
void	exit_with_error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(-1);
}

/**
 * @brief Prints an error message to the standard error output.
 *
 * @param message The error message to be printed.
 */
void	error_message(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
}
