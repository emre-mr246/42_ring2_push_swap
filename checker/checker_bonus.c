/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:53:31 by emgul             #+#    #+#             */
/*   Updated: 2024/05/21 17:11:07 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../lib/libft/libft.h"
#include "checker_bonus.h"
#include <unistd.h>

int	is_stack_sorted(t_stack_node **stack_a)
{
	if (stack_sorted(*stack_a) == 1)
	{
		ft_putstr_fd("OK\n", 1);
		return (1);
	}
	else
	{
		ft_putstr_fd("KO\n", 1);
		return (-1);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	char			**input;

	input = NULL;
	if (argc == 1)
		return (-1);
	input = create_input(argc, argv);
	stack_a = init_stack_a(input);
	free_input(input);
	check_duplicate(&stack_a);
	if (stack_a && stack_sorted(stack_a) <= 0)
	{
		sort_by_input(&stack_a);
		is_stack_sorted(&stack_a);
	}
	if (stack_a)
		free_stack(stack_a);
	return (0);
}
