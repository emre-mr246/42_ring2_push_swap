/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:54:31 by emgul             #+#    #+#             */
/*   Updated: 2024/05/09 19:21:05 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>

void	sort_stack(t_stack_node **stack_a)
{
	if (get_stack_len(*stack_a) == 2)
		sa(stack_a, false);
	else if (get_stack_len(*stack_a) == 3)
		sort_three(stack_a);
	else
		sort_algorithm(stack_a);
}

void	sort_algorithm(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;
	int				len_a;

	stack_b = NULL;
	len_a = get_stack_len(*stack_a);
	if (len_a-- > 3 && stack_sorted(*stack_a) <= 0)
		pb(&stack_b, stack_a, false);
	if (len_a-- > 3 && stack_sorted(*stack_a) <= 0)
		pb(&stack_b, stack_a, false);
	while (len_a-- > 3 && stack_sorted(*stack_a) <= 0)
	{
		init_nodes_a(*stack_a, stack_b);
		move_a_to_b(stack_a, &stack_b);
	}
	sort_three(stack_a);
	while (stack_b)
	{
		init_nodes_b(*stack_a, stack_b);
		move_b_to_a(stack_a, &stack_b);
	}
	set_index_and_median(*stack_a);
	lowest_node_on_top(stack_a);
}

void	sort_three(t_stack_node **stack_a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_biggest_node(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a, false);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a, false);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a, false);
}

void	move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest_node(*stack_a, *stack_b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		while (*stack_b != cheapest_node->target_node
			&& *stack_a != cheapest_node)
			rr(stack_a, stack_b, false);
		set_index_and_median(*stack_a);
		set_index_and_median(*stack_b);
	}
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
	{
		while (*stack_b != cheapest_node->target_node
			&& *stack_a != cheapest_node)
			rrr(stack_a, stack_b, false);
		set_index_and_median(*stack_a);
		set_index_and_median(*stack_b);
	}
	get_node_to_top_a(stack_a, cheapest_node);
	get_node_to_top_b(stack_b, cheapest_node->target_node);
	pb(stack_b, stack_a, false);
}

void	move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	get_node_to_top_a(stack_a, (*stack_b)->target_node);
	pa(stack_a, stack_b, false);
}
