/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:00:52 by emgul             #+#    #+#             */
/*   Updated: 2024/05/21 17:11:03 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../lib/libft/libft.h"
#include "checker_bonus.h"
#include <fcntl.h>
#include <unistd.h>

void	process_the_input(char *input, t_stack_node **stack_a,
		t_stack_node **stack_b)
{
	if (ft_strncmp(input, "pa", 2) == 0)
		pa(stack_a, stack_b, true);
	else if (ft_strncmp(input, "pb", 2) == 0)
		pb(stack_b, stack_a, true);
	else if (ft_strncmp(input, "sa", 2) == 0)
		sa(stack_a, true);
	else if (ft_strncmp(input, "sb", 2) == 0)
		sb(stack_b, true);
	else if (ft_strncmp(input, "ss", 2) == 0)
		ss(stack_a, stack_b, true);
	else if (ft_strncmp(input, "rra", 3) == 0)
		rra(stack_a, true);
	else if (ft_strncmp(input, "rrb", 3) == 0)
		rrb(stack_b, true);
	else if (ft_strncmp(input, "rrr", 3) == 0)
		rrr(stack_a, stack_b, true);
	else if (ft_strncmp(input, "ra", 2) == 0)
		ra(stack_a, true);
	else if (ft_strncmp(input, "rb", 2) == 0)
		rb(stack_b, true);
	else if (ft_strncmp(input, "rr", 2) == 0)
		rr(stack_a, stack_b, true);
	else
		error_message("Error");
}

void	sort_by_input(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;
	char			*line;

	stack_b = NULL;
	if (!*stack_a)
		return ;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (check_line(line) == -1)
			return (free(line));
		process_the_input(line, stack_a, &stack_b);
		free(line);
	}
	if (is_b_empty(&stack_b) == -1)
	{
		free_stack(*stack_a);
		free_stack(stack_b);
		exit(-1);
	}
}

int	check_line(char *line)
{
	if (line[0] == 'p' && (line[1] == 'a' || line[1] == 'b') && line[2] == '\n'
		&& !line[3])
		return (1);
	else if (line[0] == 's' && (line[1] == 'a' || line[1] == 'b'
			|| line[1] == 's') && line[2] == '\n' && !line[3])
		return (1);
	else if (line[0] == 'r' && (line[1] == 'a' || line[1] == 'b'
			|| line[1] == 'r') && line[2] == '\n' && !line[3])
		return (1);
	else if (line[0] == 'r' && line[1] == 'r' && (line[2] == 'a'
			|| line[2] == 'b' || line[2] == 'r') && line[3] == '\n' && !line[4])
		return (1);
	else
	{
		error_message("Error: invalid instruction\n");
		return (-1);
	}
}

int	is_b_empty(t_stack_node **stack_b)
{
	if (*stack_b)
	{
		error_message("stack_b cannot be empty after instructions!\n");
		return (-1);
	}
	else
		return (0);
}
