/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:03:48 by osabir            #+#    #+#             */
/*   Updated: 2023/04/29 12:08:09 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include "./../libft/libft.h"

typedef struct s_list
{
	int					i;
	int					rank;
	struct s_list		*next;
}						t_list;

typedef struct s_line
{
	int					line;
	int					line1;
	int					b_line;
	int					max;
}						t_line;

void		check_all(char *s);
void		globle_error(void);
void		check_duple2(char *s);
void		check_chara(char *s);
void		check_duple(char *s);
void		rank_stack_part1(t_list **stack_a, t_line *line);
void		rank_stack_part2(t_list **stack_a, t_line *line);
void		add_nbr(t_list **stack, int value);
void		make_stack_a(char *s, t_list **stack_a);
void		top(t_list **link, int value, int rank);
void		rra(t_list **stack_a, int i);
void		rrb(t_list **stack_b, int i);
void		rrr(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a, int i);
void		rb(t_list **stack_b, int i);
void		rr(t_list **stack_a, t_list **stack_b);
void		add_back(t_list **stack, int value, int rank);
void		sa(t_list **stack_a, int i);
void		sb(t_list **stack_b, int i);
void		ss(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_b, t_list **stack_a);
void		push_to_a(t_list **stack_a, int value, int rank);
void		pb(t_list **stack_a, t_list **stack_b);
void		push_to_b(t_list **stack_b, int value, int rank);
void		sort(t_list **stack_a, t_list **stack_b, t_line *line);
void		sort_two(t_list **stack_a);
void		sort_tree(t_list **stack_a);
void		sort_four(t_list **stack_a, t_list **stack_b);
void		sort__four1(int i, t_list **stack_a, t_list **stack_b);
void		sort__four2(int i, t_list **stack_a, t_list **stack_b);
void		sort_five(t_list **stack_a, t_list **stack_b);
void		sort__five1(int i, t_list **stack_a, t_list **stack_b);
void		sort__five2(int i, t_list **stack_a, t_list **stack_b);
void		l2b_01(int get_rank, t_list **stack_a, \
				t_list **stack_b, t_line *line);
void		l2b_00(int get_rank, t_list **stack_a, \
				t_list **stack_b, t_line *line);
void		push_2_01(int get_rank, t_list **stack_a, \
				t_list **stack_b, t_line *line);				
void		push_2_b(t_list **stack_a, t_list **stack_b, t_line *line);
void		sort_100(t_list **stack_a, t_list **stack_b, t_line *line);
void		sort_500(t_list **stack_a, t_list **stack_b, t_line *line);
void		push_2_00(int get_rank, t_list **stack_a, \
				t_list **stack_b, t_line *line);
int			big(t_list **stack_b);
void		push_2a_500(t_list **stack_a, t_list **stack_b, t_line *line);
int			big_500_2(t_list **stack_b);
void		push_500_00(int get_rank, t_list **stack_a, \
				t_list **stack_b, t_line *line);
void		push_500_01(int get_rank, t_list **stack_a, \
				t_list **stack_b, t_line *line);
void		free_it(t_list **stack);
void		ft_free_all(char **str);
void		push_2a(t_list **stack_a, t_list **stack_b, t_line *line);
void		check_sort(t_list **stack_a, t_line *line);
void		duble_nbr(t_list **stack_a, t_line *line);
void		ft_error(t_list **stack_a);
void		ft_error2(t_list **stack_a);

#endif