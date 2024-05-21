/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_to_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:06:39 by emgul             #+#    #+#             */
/*   Updated: 2024/04/30 11:59:57 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	get_node_to_top_a(t_stack_node **stack_a, t_stack_node *top_node)
{
	while (*stack_a != top_node)
	{
		if (top_node->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}

void	get_node_to_top_b(t_stack_node **stack_b, t_stack_node *top_node)
{
	while (*stack_b != top_node)
	{
		if (top_node->above_median)
			rb(stack_b, false);
		else
			rrb(stack_b, false);
	}
}

void	lowest_node_on_top(t_stack_node **stack_a)
{
	while (*stack_a != find_lowest_node(*stack_a))
	{
		if (find_lowest_node(*stack_a)->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}
