/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:27:09 by emgul             #+#    #+#             */
/*   Updated: 2024/05/21 16:43:54 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../lib/libft/libft.h"

static void	rotate(t_stack_node **first_node)
{
	t_stack_node	*last_node;

	if (!(*first_node) || !(*first_node)->next)
		return ;
	last_node = find_last_node(*first_node);
	last_node->next = *first_node;
	*first_node = (*first_node)->next;
	(*first_node)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool disable_print)
{
	rotate(a);
	if (!disable_print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack_node **b, bool disable_print)
{
	rotate(b);
	if (!disable_print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_node **a, t_stack_node **b, bool disable_print)
{
	rotate(a);
	rotate(b);
	if (!disable_print)
		ft_putstr_fd("rr\n", 1);
}
