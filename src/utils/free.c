/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:57:25 by emgul             #+#    #+#             */
/*   Updated: 2024/05/11 14:51:22 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdlib.h>

void	free_input(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	if (input)
		free(input);
}

void	free_stack(t_stack_node *node)
{
	t_stack_node	*temp;

	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}
