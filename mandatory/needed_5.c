/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:34:40 by osabir            #+#    #+#             */
/*   Updated: 2023/04/28 07:58:00 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort__five2(int i, t_list **stack_a, t_list **stack_b)
{
	if (i == 3)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_b, stack_a);
		return ;
	}
	else if (i == 4)
	{
		rra(stack_a, 1);
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_b, stack_a);
		return ;
	}
}

void	sort__five1(int i, t_list **stack_a, t_list **stack_b)
{
	if (i == 0)
	{
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_b, stack_a);
		return ;
	}
	else if (i == 1)
	{
		sa(stack_a, 1);
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_b, stack_a);
		return ;
	}
	else if (i == 2)
	{
		ra(stack_a, 1);
		sa(stack_a, 1);
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_b, stack_a);
		return ;
	}
	sort__five2(i, stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list		*stack;
	int			get_adr;
	int			i;

	get_adr = INT_MAX;
	stack = *stack_a;
	while (stack != NULL)
	{
		if (get_adr > stack->rank)
		{
			get_adr = stack->rank;
			stack = *stack_a;
		}
		stack = stack->next;
	}
	stack = *stack_a;
	i = 0;
	while (stack != NULL)
	{
		if (get_adr == stack->rank)
			break ;
		i++;
		stack = stack->next;
	}
	sort__five1(i, stack_a, stack_b);
}
