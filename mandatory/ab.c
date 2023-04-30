/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:43:29 by osabir            #+#    #+#             */
/*   Updated: 2023/04/26 15:49:59 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_b, t_list **stack_a)
{
	t_list		*stack;
	t_list		*ft_remove;

	if (*stack_b == NULL)
		return ;
	push_to_a(stack_a, (*stack_b)->i, (*stack_b)->rank);
	stack = *stack_b;
	ft_remove = stack;
	stack = stack->next;
	free(ft_remove);
	*stack_b = stack;
}

void	push_to_a(t_list **stack_a, int value, int rank)
{
	t_list		*new_stack_a;

	new_stack_a = malloc(sizeof(t_list));
	if (new_stack_a == NULL)
		return ;
	write(1, "pa\n", 3);
	new_stack_a->i = value;
	new_stack_a->rank = rank;
	new_stack_a->next = *stack_a;
	*stack_a = new_stack_a;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list		*stack;
	t_list		*ft_remove;

	if (*stack_a == NULL)
		return ;
	push_to_b(stack_b, (*stack_a)->i, (*stack_a)->rank);
	stack = *stack_a;
	ft_remove = stack;
	stack = stack->next;
	free(ft_remove);
	*stack_a = stack;
}

void	push_to_b(t_list **stack_b, int value, int rank)
{
	t_list		*new_stack_b;

	new_stack_b = malloc(sizeof(t_list));
	if (new_stack_b == NULL)
		return ;
	write(1, "pb\n", 3);
	new_stack_b->i = value;
	new_stack_b->rank = rank;
	new_stack_b->next = *stack_b;
	*stack_b = new_stack_b;
}
