/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:42:28 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/25 10:54:40 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	long			nb;
	int				index;
	int				is_in_top;
	int				total_cost;
	int				target_cost;
	int				segment;
	int				is_cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}					t_stack;

//Stack Moves
void				ft_push_top_to_stack(t_stack **src, t_stack **dst);
void				pa(t_stack **b, t_stack **a);
void				pb(t_stack **a, t_stack **b);
void				ft_swap_elements(t_stack **top);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				ft_rotate(t_stack **top);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				ft_rev_rotate(t_stack **top);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				ft_single_rotate(t_stack **stack, int count,
						void (*move)(t_stack **));
void				ft_double_rotate(t_stack **a, t_stack **b, int count,
						void (*move)(t_stack **, t_stack **));

// Parsing
void				ft_check_empty_args(int ac, char **av);
char				*ft_join_arguments(int ac, char **av);

// Init Stack
int					ft_stack_size(t_stack *lst);
void				ft_init_stack(t_stack **stack_a, char *joined_args);
void				ft_validate_and_init_stack(t_stack **a, char *joined_args);
void				ft_check_dup_and_sort(t_stack **a, t_stack **b);
void				ft_free_stack(t_stack **lst);

// Stack Utils
t_stack				*ft_stacknew(long nb);
t_stack				*ft_stacklast(t_stack *lst);
t_stack				*ft_before_last(t_stack *lst);
void				ft_stackadd_back(t_stack **lst, t_stack *New);
int					ft_is_first(t_stack *lst, int nb);
int					ft_mid_stack(t_stack *lst);
void				ft_index_in_stack(t_stack **lst);

// Cost Calcualtions
t_stack				*ft_find_cheapest(t_stack *a);
void				ft_get_cheapest(t_stack **stack);
void				ft_target_cost(t_stack **a, t_stack **b);
int					ft_calculate_node_cost(t_stack *node, int stack_length);
void				ft_total_cost(t_stack *a, t_stack *b);

// Segment Assignation
void				ft_fill_arr(t_stack *stack, int **arr);
int					*ft_find_pivots(t_stack *stack, int size, int *pivots);
void				ft_assign_segment(t_stack **a, int pivots[3]);

// Sorting Process
void				ft_sort_stack(t_stack **a, t_stack **b);
void				ft_sort_b(t_stack **a, t_stack **b);
void				ft_sort_three_a(t_stack **lst);
void				ft_sort_a(t_stack **a, t_stack **b);
void				ft_last_sort(t_stack **a);

// To Stack B Process
void				ft_prep_stack_a(t_stack **a);
void				ft_assign_cost_in_a(t_stack **a);
void				ft_get_cheapest_by_segment(t_stack **a, int seg);
void				ft_node_to_top(t_stack **a, t_stack *node);

// Back To Stack A Process
void				ft_find_target_b_in_a(t_stack *b, t_stack *a);
void				ft_prep_stack_b(t_stack **b, t_stack **a);
void				ft_both_to_top(t_stack **b, t_stack *cheapest, t_stack **a,
						int cost_b);
void				ft_b_and_target_to_top(t_stack **b, t_stack *cheapest,
						t_stack **a);

// Sorting Utilis
int					ft_is_sorted(t_stack *lst);
int					ft_is_sorted_b(t_stack *lst);
t_stack				*ft_find_max(t_stack *lst);
t_stack				*ft_find_min(t_stack *lst);

// utils
void				ft_set_cheapest_to_null(t_stack **lst);
void				ft_print_stack(t_stack *stack);
t_stack				*ft_init_b(void);

// Check Errors
int					ft_check_duplicate_in_stack(t_stack *stack);
int					ft_is_valid_number_string(char *str);
int					ft_is_not_int(t_stack *stack);
void				ft_print_error(t_stack **stack);

// Bonus
void				ft_error_checker(t_stack **a, t_stack **b, char **line);
void				ft_read_and_exec_move(t_stack **a, t_stack **b,
						char **line);
void				ft_checker(t_stack **a, t_stack **b, char **line);
void				ft_prep_main(int ac, char **av, t_stack **a, t_stack **b);

#endif
