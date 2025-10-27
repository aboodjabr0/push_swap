/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:37:27 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/27 10:35:52 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stack **stack)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest(*stack);
	if (*stack == biggest_node)
		ra(stack, 0);
	else if ((*stack)->next == biggest_node)
		rra(stack, 0);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack, 0);
}

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	push_a(a, b, 0);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len_a;

	len_a = lst_size(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (len_a-- > 3)
			push_b(a, b, 0);
	}
	quick_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	current_index(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, 0);
	else
		while (*a != smallest)
			rra(a, 0);
}
