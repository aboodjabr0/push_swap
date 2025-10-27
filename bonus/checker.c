/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:44:33 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/27 12:37:41 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	error_handling(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

static void	check_command(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		push_a(a, b, 1);
	else if (!ft_strcmp(command, "pb\n"))
		push_b(a, b, 1);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, 1);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, 1);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, 1);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, 1);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, 1);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, 1);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, 1);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, 1);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, 1);
	else
		error_handling(a, b);
}

static void	process_commands(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_command(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		stack_init(&a, ft_split(argv[1], ' '), 1);
	else
		stack_init(&a, argv + 1, 0);
	process_commands(&a, &b);
	if (sorted_stack(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
