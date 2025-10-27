/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:26:37 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/27 10:35:25 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_helper(t_stack **dest, t_stack **src)
{
	t_stack	*node;

	if (!src || !*src)
		return ;
	node = *src;
	*src = node->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	node->next = *dest;
	if (*dest)
		(*dest)->prev = node;
	*dest = node;
}

void	push_a(t_stack **a, t_stack **b, int checker)
{
	push_helper(a, b);
	if (!checker)
		ft_printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b, int checker)
{
	push_helper(b, a);
	if (!checker)
		ft_printf("pb\n");
}
