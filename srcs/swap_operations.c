/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:47:44 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/26 21:47:45 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap_helper(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	*stack = second;
}
/*********************************************************************/
/*   sa (swap a): Swap the first 2 elements at the top of stack a.   */
/*          Do nothing if there is only one element or none.         */
/*********************************************************************/

void	sa(t_stack **stack_a, int checker)
{
	swap_helper(stack_a);
	if (!checker)
		ft_printf("sa\n");
}
/*********************************************************************/
/*   sb (swap b): Swap the first 2 elements at the top of stack b    */
/*       Do nothing if there is only one element or none.            */
/*********************************************************************/

void	sb(t_stack **stack_b, int checker)
{
	swap_helper(stack_b);
	if (!checker)
		ft_printf("sb\n");
}

/**************************************/
/*    sa and sb at the same time.     */
/**************************************/
void	ss(t_stack **stack_a, t_stack **stack_b, int checker)
{
	swap_helper(stack_a);
	swap_helper(stack_b);
	if (!checker)
		ft_printf("ss\n");
}
