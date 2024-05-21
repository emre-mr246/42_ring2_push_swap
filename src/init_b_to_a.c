/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:35:38 by emgul             #+#    #+#             */
/*   Updated: 2024/05/21 19:57:00 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	set_index_and_median(a);
	set_index_and_median(b);
	set_target_b(a, b);
}

void	set_target_b(t_stack_node *node_a, t_stack_node *node_b)
{
	t_stack_node	*pointer_a;
	t_stack_node	*target_node;
	long			closest_bigger_nbr;

	while (node_b)
	{
		closest_bigger_nbr = LONG_MAX;
		pointer_a = node_a;
		while (pointer_a)
		{
			if (pointer_a->nbr > node_b->nbr
				&& pointer_a->nbr < closest_bigger_nbr)
			{
				closest_bigger_nbr = pointer_a->nbr;
				target_node = pointer_a;
			}
			pointer_a = pointer_a->next;
		}
		if (closest_bigger_nbr == LONG_MAX)
			node_b->target_node = find_lowest_node(node_a);
		else
			node_b->target_node = target_node;
		node_b = node_b->next;
	}
}
