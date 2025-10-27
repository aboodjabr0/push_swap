/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:24:37 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/26 21:45:28 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack **a, char **argv, int argc_is_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (validate_number(argv[i]))
			free_and_exit(a, argv, argc_is_2);
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_and_exit(a, argv, argc_is_2);
		if (check_duplicates(*a, (int)nbr))
			free_and_exit(a, argv, argc_is_2);
		append_node(a, (int)nbr);
		i++;
	}
}

int	sorted_stack(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
