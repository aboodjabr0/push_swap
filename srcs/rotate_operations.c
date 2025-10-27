/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:53:44 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/26 21:54:14 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_helper(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	last = find_last_node(*stack);
	last->next = first;
	first->prev = last;
}

void	ra(t_stack **a, int checker)
{
	rotate_helper(a);
	if (!checker)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int checker)
{
	rotate_helper(b);
	if (!checker)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int checker)
{
	rotate_helper(a);
	rotate_helper(b);
	if (!checker)
		ft_printf("rr\n");
}
