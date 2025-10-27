/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:44:05 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/26 22:27:47 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				current_position;
	int				above_median;
	int				push_price;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/****************************/
/*    swap_operations.c     */
/****************************/
void				swap_helper(t_stack **stack);
void				sa(t_stack **stack_a, int checker);
void				sb(t_stack **stack_b, int checker);
void				ss(t_stack **stack_a, t_stack **stack_b, int checker);

/****************************/
/*     push_operations.c    */
/****************************/
void				push_helper(t_stack **dest, t_stack **src);
void				push_a(t_stack **a, t_stack **b, int checker);
void				push_b(t_stack **b, t_stack **a, int checker);

/****************************/
/*    rotate_operations.c   */
/****************************/
void				rotate_helper(t_stack **stack);
void				ra(t_stack **stack_a, int checker);
void				rb(t_stack **stack_b, int checker);
void				rr(t_stack **stack_a, t_stack **stack_b, int checker);

/************************************/
/*    reverse_rotate_operations.c   */
/************************************/
void				reverse_rotate(t_stack **stack);
void				rra(t_stack **stack_a, int checker);
void				rrb(t_stack **stack_b, int checker);
void				rrr(t_stack **stack_a, t_stack **stack_b, int checker);

/************************************/
/*         error_handling.c         */
/************************************/
int					validate_number(char *nbr);
void				free_stack(t_stack **stack);
void				free_and_exit(t_stack **a, char **argv, int check_argc);
void				free_matrix(char **argv);
int					check_duplicates(t_stack *a, int nbr);

/************************************/
/*           stack_init.c           */
/************************************/
void				stack_init(t_stack **a, char **argv, int argc_is_2);
int					sorted_stack(t_stack *stack);

/************************************/
/*           stack_helpers.c        */
/************************************/
t_stack				*find_last_node(t_stack *stack);
void				append_node(t_stack **stack, int nbr);
t_stack				*find_smallest(t_stack *stack);
t_stack				*find_biggest(t_stack *stack);
long int			lst_size(t_stack *stack);

/************************************/
/*           sorting_algo.c         */
/************************************/
void				quick_sort(t_stack **stack);
void				move_nodes(t_stack **a, t_stack **b);
void				push_swap(t_stack **a, t_stack **b);

/************************************/
/*           sorting_algo_2.c       */
/************************************/
void				sort_five(t_stack **a, t_stack **b);
void				finish_rotation(t_stack **stack, t_stack *top_node,
						char stack_name);
t_stack				*return_cheapest(t_stack *stack);

/************************************/
/*           sorting_helpers.c      */
/************************************/
void				current_index(t_stack *stack);
void				target_node(t_stack *a, t_stack *b);
void				price(t_stack *a, t_stack *b);
void				cheapest(t_stack *b);
void				init_nodes(t_stack *a, t_stack *b);

/************************************/
/*           sorting_helpers_2.c    */
/************************************/
void				rotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);
void				reverse_rotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);

#endif