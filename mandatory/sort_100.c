/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:17:42 by osabir            #+#    #+#             */
/*   Updated: 2023/04/29 14:54:33 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	l2b_01(int get_rank, t_list **stack_a, t_list **stack_b, t_line *line)
{
	t_list		*stack;

	stack = *stack_a;
	while (1)
	{
		if (get_rank == stack->rank)
		{
			pb(stack_a, stack_b);
			break ;
		}
		ra(stack_a, 1);
		stack = *stack_a;
	}
	line->line--;
	line->b_line++;
}

void	l2b_00(int get_rank, t_list **stack_a, t_list **stack_b, t_line *line)
{
	t_list		*stack;

	stack = *stack_a;
	while (1)
	{
		if (get_rank == stack->rank)
		{
			pb(stack_a, stack_b);
			break ;
		}
		rra(stack_a, 1);
		stack = *stack_a;
	}
	line->line--;
	line->b_line++;
}

void	push_2_b(t_list **stack_a, t_list **stack_b, t_line *line)
{
	t_list		*stack;
	int			get_rank;
	int			i;
	int			j;

	i = line->max;
	j = 0;
	get_rank = 0;
	stack = *stack_a;
	if (*stack_a == NULL)
		return ;
	while (stack != NULL)
	{
		if (i > stack->rank)
		{
			get_rank = stack->rank;
			break ;
		}
		j++;
		stack = stack->next;
	}
	if (line->line / 2 < j)
		l2b_00(get_rank, stack_a, stack_b, line);
	else if ((line->line / 2 > j) || (line->line / 2 == j))
		l2b_01(get_rank, stack_a, stack_b, line);
}

void	sort_100(t_list **stack_a, t_list **stack_b, t_line *line)
{
	t_list		*stack;
	int			i;
	int			j;
	int			lion;

	i = line->line / 4;
	j = i;
	lion = 0;
	while (i <= line->line1)
	{
		while (lion < i)
		{
			line->max = i;
			push_2_b(stack_a, stack_b, line);
			lion++;
		}
		i += j;
	}
	stack = *stack_b;
	while (stack != NULL)
	{
		push_2a(stack_a, stack_b, line);
		stack = *stack_b;
	}
}
