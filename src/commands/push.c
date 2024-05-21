/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:01:58 by emgul             #+#    #+#             */
/*   Updated: 2024/05/21 16:43:45 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../lib/libft/libft.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*temp;

	if (!(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->prev = NULL;
	if (!*dst)
	{
		*dst = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dst;
		temp->next->prev = temp;
		*dst = temp;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool disable_print)
{
	push(a, b);
	if (!disable_print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack_node **b, t_stack_node **a, bool disable_print)
{
	push(b, a);
	if (!disable_print)
		ft_putstr_fd("pb\n", 1);
}
