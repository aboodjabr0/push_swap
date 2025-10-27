/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 03:56:54 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/26 22:27:47 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, 0);
	current_index(*a);
	current_index(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, 0);
	current_index(*a);
	current_index(*b);
}
