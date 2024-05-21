/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:16:14 by emgul             #+#    #+#             */
/*   Updated: 2024/05/21 16:43:42 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../lib/libft/libft.h"

static void	rev_rotate(t_stack_node **first_node)
{
	t_stack_node	*last_node;

	if (!(*first_node) || !(*first_node)->next)
		return ;
	last_node = find_last_node(*first_node);
	last_node->prev->next = NULL;
	last_node->next = *first_node;
	last_node->prev = NULL;
	*first_node = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, bool disable_print)
{
	rev_rotate(a);
	if (!disable_print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack_node **b, bool disable_print)
{
	rev_rotate(b);
	if (!disable_print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool disable_print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!disable_print)
		ft_putstr_fd("rrr\n", 1);
}
