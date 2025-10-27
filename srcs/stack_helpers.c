/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 22:02:53 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/26 21:43:50 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->data = nbr;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack	*find_smallest(t_stack *stack)
{
	long	smallest;
	t_stack	*smallest_node;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->data < smallest)
		{
			smallest = stack->data;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*find_biggest(t_stack *stack)
{
	long	biggest;
	t_stack	*biggest_node;

	if (!stack)
		return (NULL);
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->data > biggest)
		{
			biggest = stack->data;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

long int	lst_size(t_stack *stack)
{
	long int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
