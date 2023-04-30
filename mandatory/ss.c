/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:30:54 by osabir            #+#    #+#             */
/*   Updated: 2023/04/26 15:40:00 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int i)
{
	t_list		*stack;
	t_list		*tmp;
	t_list		*ft_remove;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (i == 1)
		write(1, "sa\n", 3);
	tmp = malloc(sizeof(stack_a));
	tmp->i = (*stack_a)->next->i;
	tmp->rank = (*stack_a)->next->rank;
	stack = *stack_a;
	ft_remove = stack->next;
	stack->next = stack->next->next;
	free(ft_remove);
	tmp->next = *stack_a;
	*stack_a = tmp;
}

void	sb(t_list **stack_b, int i)
{
	t_list		*stack;
	t_list		*tmp;
	t_list		*ft_remove;

	if (*link == NULL || (*stack_b)->next == NULL)
		return ;
	if (i == 1)
		write(1, "sa\n", 3);
	tmp = malloc(sizeof(stack_b));
	tmp->i = (*stack_b)->next->i;
	tmp->rank = (*stack_b)->next->rank;
	stack = *stack_b;
	ft_remove = stack->next;
	stack->next = stack->next->next;
	free(ft_remove);
	tmp->next = *stack_b;
	*stack_b = tmp;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}
