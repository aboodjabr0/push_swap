/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:12:47 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/24 23:04:57 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_arguments(int argc, char **argv, t_stack **a,
		char ***split_argv)
{
	if (argc == 2)
	{
		*split_argv = ft_split(argv[1], ' ');
		stack_init(a, *split_argv, 1);
	}
	else
		stack_init(a, argv + 1, 0);
}

static void	sort_stack(t_stack **a, t_stack **b)
{
	if (lst_size(*a) == 2)
		sa(a, 0);
	else if (lst_size(*a) == 3)
		quick_sort(a);
	else
		push_swap(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_argv;

	a = NULL;
	b = NULL;
	split_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	handle_arguments(argc, argv, &a, &split_argv);
	if (!sorted_stack(a))
		sort_stack(&a, &b);
	free_stack(&a);
	if (split_argv)
		free_matrix(split_argv);
	return (0);
}
