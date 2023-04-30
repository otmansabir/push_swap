/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 07:32:04 by osabir            #+#    #+#             */
/*   Updated: 2023/04/28 16:51:56 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_500_01(int get_rank, t_list **stack_a, \
		t_list **stack_b, t_line *line)
{
	t_list		*stack;

	stack = *stack_b;
	while (1)
	{
		if (get_rank == stack->rank)
		{
			pa(stack_b, stack_a);
			break ;
		}
		rb(stack_b, 1);
		stack = *stack_b;
	}
	line->b_line--;
}

void	push_500_00(int get_rank, t_list **stack_a, \
		t_list **stack_b, t_line *line)
{
	t_list		*stack;

	stack = *stack_b;
	while (1)
	{
		if (get_rank == stack->rank)
		{
			pa(stack_b, stack_a);
			break ;
		}
		rrb(stack_b, 1);
		stack = *stack_b;
	}
	line->b_line--;
}

int	big_500_2(t_list **stack_b)
{
	t_list	*stack;
	int		get_rank;

	stack = *stack_b;
	get_rank = 0;
	while (stack != NULL)
	{
		if (get_rank < stack->rank)
		{
			get_rank = stack->rank;
			stack = *stack_b;
		}
		stack = stack->next;
	}
	return (get_rank);
}

void	push_2a_500(t_list **stack_a, t_list **stack_b, t_line *line)
{
	t_list		*stack;
	int			get_rank;
	int			j;

	j = 0;
	if (*stack_b == NULL)
		return ;
	get_rank = big_500_2(stack_b);
	stack = *stack_b;
	while (stack != NULL)
	{
		if (get_rank == stack->rank)
			break ;
		j++;
		stack = stack->next;
	}
	if ((line->b_line / 2 > j) || (line->b_line / 2 == j))
		push_500_01(get_rank, stack_a, stack_b, line);
	else if (line->b_line / 2 < j)
		push_500_00(get_rank, stack_a, stack_b, line);
}
