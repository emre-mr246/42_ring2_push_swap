/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:48:29 by emgul             #+#    #+#             */
/*   Updated: 2024/05/22 12:16:31 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../lib/libft/libft.h"
#include <limits.h>

int	stack_sorted(t_stack_node *node)
{
	if (!node)
		return (-1);
	while (node->next)
	{
		if (node->nbr > node->next->nbr)
			return (0);
		node = node->next;
	}
	return (1);
}

int	get_stack_len(t_stack_node *node)
{
	int	len;

	if (!node)
		return (0);
	len = 0;
	while (node)
	{
		node = node->next;
		len++;
	}
	return (len);
}

int	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*temp;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return (-1);
	node->next = NULL;
	node->nbr = nbr;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		temp = find_last_node(*stack);
		temp->next = node;
		node->prev = temp;
	}
	return (0);
}

void	set_index_and_median(t_stack_node *node)
{
	int	i;
	int	median;

	i = 0;
	if (!node)
		return ;
	median = get_stack_len(node) / 2;
	while (node)
	{
		node->index = i;
		if (i <= median)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
		i++;
	}
}

/**
 * @brief Initializes stack A with integers parsed from input strings.
 *
 * @param input Array of strings representing integers
 *  to initialize the stack with.
 * @return A pointer to the head of the initialized stack A,
 *  or NULL if an error occurs.
 */
t_stack_node	*init_stack_a(char **input)
{
	t_stack_node	*stack_a;
	long			nbr;

	stack_a = NULL;
	while (*input)
	{
		nbr = ft_atol(*input);
		if (nbr < INT_MIN || nbr > INT_MAX)
		{
			error_message("The input exceeds the bounds of an integer.");
			return (NULL);
		}
		if (append_node(&stack_a, (int)nbr) == -1)
		{
			free_stack(stack_a);
			error_message("the node could not be created.");
			return (NULL);
		}
		input++;
	}
	return (stack_a);
}
