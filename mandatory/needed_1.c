/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:18:46 by osabir            #+#    #+#             */
/*   Updated: 2023/04/30 11:48:14 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_stack_part1(t_list **stack_a, t_line *line)
{
	t_list	*stack;
	t_list	*tmp;
	long	i;
	int		j;

	j = 0;
	rank_stack_part2(stack_a, line);
	stack = *stack_a;
	while (line->line != j)
	{
		i = LONG_MAX;
		while (stack != NULL)
		{
			if (i > stack->i && stack->rank == -1)
			{
				i = stack->i;
				tmp = stack;
				stack = *stack_a;
			}
			stack = stack->next;
		}
		if (tmp->rank == -1)
			tmp->rank = j++;
		stack = *stack_a;
	}
}

void	rank_stack_part2(t_list **stack_a, t_line *line)
{
	t_list	*stack;

	stack = *stack_a;
	line->line = 0;
	line->line1 = 0;
	while (stack != NULL)
	{
		stack->rank = -1;
		stack = stack->next;
		line->line++;
		line->line1++;
	}
}

void	ft_error(t_list **stack_a)
{
	free_it(stack_a);
	exit(0);
}

void	ft_error2(t_list **stack_a)
{
	free_it(stack_a);
	globle_error();
}
