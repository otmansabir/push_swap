/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:29:11 by osabir            #+#    #+#             */
/*   Updated: 2023/04/28 07:57:07 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort__four2(int i, t_list **stack_a, t_list **stack_b)
{
	if (i == 2)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
		pb(stack_a, stack_b);
		sort_tree(stack_a);
		pa(stack_b, stack_a);
		return ;
	}
	else if (i == 3)
	{
		rra(stack_a, 1);
		pb(stack_a, stack_b);
		sort_tree(stack_a);
		pa(stack_b, stack_a);
		return ;
	}
}

void	sort__four1(int i, t_list **stack_a, t_list **stack_b)
{
	if (i == 0)
	{
		pb(stack_a, stack_b);
		sort_tree(stack_a);
		pa(stack_b, stack_a);
		return ;
	}
	else if (i == 1)
	{
		sa(stack_a, 1);
		pb(stack_a, stack_b);
		sort_tree(stack_a);
		pa(stack_b, stack_a);
		return ;
	}
	sort__four2(i, stack_a, stack_b);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
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
	sort__four1(i, stack_a, stack_b);
}
