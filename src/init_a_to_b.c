/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:15:33 by emgul             #+#    #+#             */
/*   Updated: 2024/05/04 16:30:28 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stddef.h>

void	set_targets(t_stack_node *node_a, t_stack_node *node_b)
{
	t_stack_node	*pointer_b;
	t_stack_node	*target_node;
	int				closest_smaller_nbr;

	while (node_a)
	{
		closest_smaller_nbr = INT_MIN;
		pointer_b = node_b;
		while (pointer_b)
		{
			if (pointer_b->nbr < node_a->nbr
				&& pointer_b->nbr > closest_smaller_nbr)
			{
				closest_smaller_nbr = pointer_b->nbr;
				target_node = pointer_b;
			}
			pointer_b = pointer_b->next;
		}
		if (closest_smaller_nbr == INT_MIN)
			node_a->target_node = find_biggest_node(node_b);
		else
			node_a->target_node = target_node;
		node_a = node_a->next;
	}
}

void	calculate_costs(t_stack_node *node_a, t_stack_node *node_b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_len(node_a);
	len_b = get_stack_len(node_b);
	while (node_a)
	{
		node_a->push_cost = node_a->index;
		if (!(node_a->above_median))
			node_a->push_cost = len_a - (node_a->index);
		if (node_a->target_node->above_median)
			node_a->push_cost += node_a->target_node->index;
		else
			node_a->push_cost += len_b - (node_a->target_node->index);
		node_a = node_a->next;
	}
}

t_stack_node	*get_cheapest_node(t_stack_node *node_a, t_stack_node *node_b)
{
	t_stack_node	*cheapest_node;
	int				cheapest_value;

	if (!node_a)
		return (NULL);
	cheapest_value = INT_MAX;
	calculate_costs(node_a, node_b);
	while (node_a)
	{
		if (node_a->push_cost < cheapest_value)
		{
			cheapest_value = node_a->push_cost;
			cheapest_node = node_a;
		}
		node_a = node_a->next;
	}
	return (cheapest_node);
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_index_and_median(a);
	set_index_and_median(b);
	set_targets(a, b);
}
