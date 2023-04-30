/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   para_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:32:41 by osabir            #+#    #+#             */
/*   Updated: 2023/04/30 11:36:12 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	globle_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

void	check_duple2(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		globle_error();
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9' && (s[i + 1] == '+' || s[i + 1] == '-'))
			globle_error();
		if ((s[i] == '+' || s[i] == '-') && (s[i + 1] == ' '))
			globle_error();
		if ((s[i] == '+' || s[i] == '-') && (s[i + 1] == '\0'))
			globle_error();
		i++;
	}
}

void	check_chara(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		globle_error();
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '+'
			|| s[i] == '-' || s[i] == ' ')
			i++;
		else
			globle_error();
	}
}

void	check_duple(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		globle_error();
	while (s[i])
	{
		if (s[i] == '+' && (s[i + 1] == '+' || s[i + 1] == '-'))
			globle_error();
		if (s[i] == '-' && (s[i + 1] == '+' || s[i + 1] == '-'))
			globle_error();
		i++;
	}
}
