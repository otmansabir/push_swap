/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:09:22 by osabir            #+#    #+#             */
/*   Updated: 2023/04/28 07:59:00 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top(t_list **link, int value, int rank)
{
	t_list		*new_nbr;

	new_nbr = malloc(sizeof(link));
	if (!new_nbr)
		return ;
	new_nbr->i = value;
	new_nbr->rank = rank;
	new_nbr->next = *link;
	*link = new_nbr;
}

void	rra(t_list **stack_a, int i)
{
	t_list		*stack;
	t_list		*tmp;
	t_list		*ft_remove;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (i == 1)
		write(1, "rra\n", 4);
	stack = *stack_a;
	tmp = malloc(sizeof(stack_a));
	while (stack->next->next != NULL)
	{
		stack = stack->next;
	}
	tmp->i = stack->next->i;
	tmp->rank = stack->next->rank;
	ft_remove = stack->next;
	free(ft_remove);
	stack->next = NULL;
	top(stack_a, tmp->i, tmp->rank);
	free(tmp);
}

void	rrb(t_list **stack_b, int i)
{
	t_list		*stack;
	t_list		*tmp;
	t_list		*ft_remove;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	if (i == 1)
		write(1, "rrb\n", 4);
	stack = *stack_b;
	tmp = malloc(sizeof(stack_b));
	while (stack->next->next != NULL)
	{
		stack = stack->next;
	}
	tmp->i = stack->next->i;
	tmp->rank = stack->next->rank;
	ft_remove = stack->next;
	free(ft_remove);
	stack->next = NULL;
	top(stack_b, tmp->i, tmp->rank);
	free(tmp);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrb(stack_a, 0);
	rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
