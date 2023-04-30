/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:07:23 by osabir            #+#    #+#             */
/*   Updated: 2023/04/28 16:04:20 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack_a)
{
	t_list		*stack;

	stack = *stack_a;
	if (stack->i > stack->next->i)
		sa(stack_a, 1);
}

void	sort_tree(t_list **stack_a)
{
	t_list		*stack;

	stack = *stack_a;
	if (stack->i > stack->next->i && stack->i < stack->next->next->i \
		&& stack->next->i < stack->next->next->i)
		sa(stack_a, 1);
	else if (stack->i > stack->next->i && stack->i > stack->next->next->i \
		&& stack->next->i > stack->next->next->i)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (stack->i > stack->next->i && stack->i > stack->next->next->i \
		&& stack->next->i < stack->next->next->i)
		ra(stack_a, 1);
	else if (stack->i < stack->next->i && stack->i < stack->next->next->i \
		&& stack->next->i > stack->next->next->i)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (stack->i < stack->next->i && stack->i > stack->next->next->i \
		&& stack->next->i > stack->next->next->i)
		rra(stack_a, 1);
}

void	sort(t_list **stack_a, t_list **stack_b, t_line *line)
{	
	if (line->line == 2)
		sort_two(stack_a);
	if (line->line == 3)
		sort_tree(stack_a);
	if (line->line == 4)
		sort_four(stack_a, stack_b);
	if (line->line == 5)
		sort_five(stack_a, stack_b);
	if (line->line > 5 && line->line <= 100)
		sort_100(stack_a, stack_b, line);
	if (line->line > 100)
		sort_500(stack_a, stack_b, line);
}
