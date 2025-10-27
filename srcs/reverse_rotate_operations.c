/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:07:03 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/26 21:53:43 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/***********************************************************/
/*                 Reverse rotate operation: moves the     */
/*                last element of the stack to the top     */
/***********************************************************/

void	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	tail = find_last_node(head);
	if (tail == head)
		return ;
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	*stack = tail;
}

void	rra(t_stack **a, int checker)
{
	reverse_rotate(a);
	if (!checker)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int checker)
{
	reverse_rotate(b);
	if (!checker)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		ft_printf("rrr\n");
}
