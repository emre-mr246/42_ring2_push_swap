/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:56:11 by emgul             #+#    #+#             */
/*   Updated: 2024/05/09 19:01:54 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

t_stack_node	*ft_lstdup(t_stack_node *stack);
int				is_stack_sorted(t_stack_node **stack_a);
int				check_line(char *line);
void			sort_by_input(t_stack_node **stack_a);
void			process_the_input(char *input, t_stack_node **stack_a,
					t_stack_node **stack_b);
int				is_b_empty(t_stack_node **stack_b);
