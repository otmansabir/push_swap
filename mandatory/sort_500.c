/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:41:58 by osabir            #+#    #+#             */
/*   Updated: 2023/04/30 13:02:49 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	use_ra(int get_rank, t_list **stack_a, t_list **stack_b, t_line *line)
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

void	use_rra(int get_rank, t_list **stack_a, t_list **stack_b, t_line *line)
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

void	push_500_b(t_list **stack_a, t_list **stack_b, t_line *line)
{
	t_list		*stack;
	int			get_rank;
	int			i;
	int			j;

	i = line->max;
	j = 0;
	get_rank = 0;
	stack = *stack_a;
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
		use_rra(get_rank, stack_a, stack_b, line);
	else if ((line->line / 2 > j) || (line->line / 2 == j))
		use_ra(get_rank, stack_a, stack_b, line);
}

void	sort_500(t_list **stack_a, t_list **stack_b, t_line *line)
{
	t_list		*stack;
	int			i;
	int			j;
	int			lion;

	i = line->line / 10;
	j = i;
	lion = 0;
	while (i <= line->line1)
	{
		while (lion < i)
		{
			line->max = i;
			push_500_b(stack_a, stack_b, line);
			lion++;
		}
		i += j;
	}
	stack = *stack_b;
	while (stack != NULL)
	{
		push_2a_500(stack_a, stack_b, line);
		stack = *stack_b;
	}
}
