/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:55:20 by osabir            #+#    #+#             */
/*   Updated: 2023/04/30 11:37:13 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack_a(char *s, t_list **stack_a)
{
	char	**did;
	int		i;
	long	nbr;

	i = 0;
	if (!s || !s[0])
		globle_error();
	did = ft_split(s, ' ');
	if (!did || !did[0])
		globle_error();
	while (did[i])
	{
		nbr = ft_atoi(did[i++]);
		if (nbr == LONG_MAX)
		{
			printf("error \n");
			exit(1);
		}
		add_nbr(stack_a, (int)nbr);
	}
	ft_free_all(did);
}

void	ft_free_all(char **str)
{
	int	n;

	n = 0;
	while (str[n] != NULL)
	{
		free(str[n]);
		n++;
	}
	free(str);
}

void	add_nbr(t_list **stack, int value)
{
	t_list	*new_nbr;
	t_list	*curr;

	new_nbr = malloc(sizeof(stack));
	if (!new_nbr)
		exit(1);
	new_nbr->i = value;
	new_nbr->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_nbr;
		return ;
	}
	curr = *stack;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_nbr;
}
