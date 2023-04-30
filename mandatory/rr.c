/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:20:31 by osabir            #+#    #+#             */
/*   Updated: 2023/04/26 15:42:19 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int i)
{
	t_list		*stack;
	t_list		*tmp;
	t_list		*ft_remove;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (i == 1)
		write(1, "ra\n", 3);
	stack = *stack_a;
	tmp = malloc(sizeof(stack_a));
	tmp->i = (*stack_a)->i;
	tmp->rank = (*stack_a)->rank;
	add_back(stack_a, tmp->i, tmp->rank);
	ft_remove = stack;
	stack = stack->next;
	free(ft_remove);
	free(tmp);
	*stack_a = stack;
}

void	rb(t_list **stack_b, int i)
{
	t_list		*stack;
	t_list		*tmp;
	t_list		*ft_remove;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	if (i == 1)
		write(1, "rb\n", 3);
	stack = *stack_b;
	tmp = malloc(sizeof(stack_b));
	tmp->i = (*stack_b)->i;
	tmp->rank = (*stack_b)->rank;
	add_back(stack_b, tmp->i, tmp->rank);
	ft_remove = stack;
	stack = stack->next;
	free(ft_remove);
	free(tmp);
	*stack_b = stack;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}

void	add_back(t_list **stack, int value, int rank)
{
	t_list	*new_nbr;
	t_list	*satck;

	new_nbr = malloc(sizeof(stack));
	if (!new_nbr)
		exit(1);
	new_nbr->i = value;
	new_nbr->rank = rank;
	new_nbr->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_nbr;
		return ;
	}
	satck = *stack;
	while (satck->next != NULL)
	{
		satck = satck->next;
	}
	satck->next = new_nbr;
}
