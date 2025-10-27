/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:55:48 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/26 22:27:47 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int	i;
	int	center_line;

	i = 0;
	if (!stack)
		return ;
	center_line = lst_size(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= center_line)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	target_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_index;

	while (b)
	{
		best_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->data > b->data && current_a->data < best_index)
			{
				best_index = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_index)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	price(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = lst_size(a);
	b_len = lst_size(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = b_len - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += a_len - (b->target_node->current_position);
		b = b->next;
	}
}

void	cheapest(t_stack *b)
{
	long	best_match;
	t_stack	*best_match_node;

	if (!b)
		return ;
	best_match = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match)
		{
			best_match = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = 1;
}

void	init_nodes(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	target_node(a, b);
	price(a, b);
	cheapest(b);
}
