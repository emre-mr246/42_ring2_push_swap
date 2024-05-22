/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:57:24 by emgul             #+#    #+#             */
/*   Updated: 2024/05/22 12:06:30 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// COMMANDS
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);

// SORT
void					sort_stack(t_stack_node **stack_a);
void					sort_three(t_stack_node **stack_a);
void					sort_algorithm(t_stack_node **stack_a);

// UTILS
long					ft_atol(const char *str);
char					**parse_input(int argc, char **argv);
int						get_argv_len(char **argv);
char					**create_input(int argc, char **argv);
int						str_arr_size(char **input);

// STACK UTILS
int						get_stack_len(t_stack_node *node);
int						stack_sorted(t_stack_node *node);
t_stack_node			*init_stack_a(char **argv);
int						append_node(t_stack_node **stack, int nbr);
void					set_index_and_median(t_stack_node *node);
t_stack_node			*get_cheapest_node(t_stack_node *node_a,
							t_stack_node *node_b);

// FIND
t_stack_node			*find_last_node(t_stack_node *node);
t_stack_node			*find_biggest_node(t_stack_node *node);
t_stack_node			*find_lowest_node(t_stack_node *node);

// GET NODE TO TOP
void					get_node_to_top_a(t_stack_node **stack_a,
							t_stack_node *top_node);
void					get_node_to_top_b(t_stack_node **stack_b,
							t_stack_node *top_node);
void					lowest_node_on_top(t_stack_node **stack_a);

// ERROR
void					exit_with_error(char *message);
void					error_message(char *message);

// CHECK
void					check_duplicate(t_stack_node **stack_a);
int						check_input(char **input);
int						check_syntax(char *str);

// FREE

void					free_input(char **input);
void					free_stack(t_stack_node *node);

// INIT
void					init_nodes_a(t_stack_node *a, t_stack_node *b);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);
t_stack_node			*init_stack_b(void);

// MOVE
void					move_a_to_b(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					move_b_to_a(t_stack_node **stack_a,
							t_stack_node **stack_b);

void					set_target_b(t_stack_node *node_a,
							t_stack_node *node_b);

#endif