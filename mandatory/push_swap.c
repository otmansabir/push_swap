/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:03:46 by osabir            #+#    #+#             */
/*   Updated: 2023/04/30 13:06:29 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_it(t_list **stack)
{
	t_list		*curr;
	t_list		*aux;

	curr = *stack;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	*stack = NULL;
}

void	duble_nbr(t_list **stack_a, t_line *line)
{
	t_list		*stack;
	t_list		*stack2;
	int			get;

	if (line->line == 1)
		ft_error(stack_a);
	stack = *stack_a;
	stack2 = stack->next;
	get = stack->i;
	while (stack != NULL)
	{
		while (stack2 != NULL)
		{
			if (get == stack2->i)
				ft_error2(stack_a);
			stack2 = stack2->next;
		}
		stack = stack->next;
		get = stack->i;
		stack2 = stack->next;
		if (stack->next == NULL)
			return ;
	}
}

void	check_all(char *s)
{
	check_chara(s);
	check_duple2(s);
	check_duple(s);
}

void	check_sort(t_list **stack_a, t_line *line)
{
	t_list		*stack;

	if (line->line == 1)
	{
		free_it(stack_a);
		exit(0);
	}
	stack = *stack_a;
	while (stack != NULL)
	{
		if (stack->i > stack->next->i)
			return ;
		stack = stack->next;
		if (stack->next == NULL)
			break ;
	}
	free_it(stack_a);
	exit(0);
}

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_line		line;
	int			i;

	if (ac > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		i = 1;
		while (av[i])
			check_all(av[i++]);
		i = 1;
		while (av[i])
			make_stack_a(av[i++], &stack_a);
		rank_stack_part1(&stack_a, &line);
		duble_nbr(&stack_a, &line);
		check_sort(&stack_a, &line);
		sort(&stack_a, &stack_b, &line);
		free_it(&stack_a);
	}
	return (0);
}
