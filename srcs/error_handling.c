/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:28:08 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/26 21:46:00 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_number(char *nbr)
{
	int	i;

	i = 0;
	if (!(nbr[i] == '+' || nbr[i] == '-' || ft_isdigit(nbr[i])))
		return (1);
	if ((nbr[i] == '+' || nbr[i] == '-') && !ft_isdigit(nbr[i + 1]))
		return (1);
	i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (1);
		i++;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	free_and_exit(t_stack **a, char **argv, int check_argc)
{
	free_stack(a);
	if (check_argc)
		free_matrix(argv);
	ft_printf("Error\n");
	exit(1);
}

void	free_matrix(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

int	check_duplicates(t_stack *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->data == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
