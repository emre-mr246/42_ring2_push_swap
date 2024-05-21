/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:56:43 by emgul             #+#    #+#             */
/*   Updated: 2024/05/21 20:07:24 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../lib/libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	char			**input;

	input = NULL;
	if (argc == 1)
		return (-1);
	input = create_input(argc, argv);
	stack_a = init_stack_a(input);
	if (input)
		free_input(input);
	if (stack_a)
		check_duplicate(&stack_a);
	if (stack_a && stack_sorted(stack_a) <= 0)
		sort_stack(&stack_a);
	if (stack_a)
		free_stack(stack_a);
	return (0);
}
