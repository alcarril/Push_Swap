/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:05:51 by alex              #+#    #+#             */
/*   Updated: 2025/02/28 16:06:26 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_nums(t_head *head)
{
	if (!head || !head->list_a)
		return ;
	if (head->stack_a_len < 3)
	{
		if (head->list_a->next == head->list_a)
			return ;
		else if (head->list_a->num > head->list_a->next->num)
			swp_a(&(head->list_a), 1);
	}
	else if (head->stack_a_len == 3)
		short_three_a(&(head->list_a));
	else if (head->stack_a_len == 5)
		short_five(head);
	else if (head->stack_a_len > 3 && head->stack_a_len != 5)
		short_big(head);
}

void	short_three_a(t_node **list_a)
{
	t_node	*max;
	t_node	*min;

	if (!list_a || !*list_a || ft_is_short(*list_a))
		return ;
	max = search_max(*list_a);
	min = search_min(*list_a);
	if (max == *list_a)
		r_a(list_a, 1);
	else if (max == (*list_a)->next)
	{
		swp_a(list_a, 1);
		r_a(list_a, 1);
	}
	else if (max == (*list_a)->next->next)
	{
		if (min == list_a[0]->next)
			swp_a(list_a, 1);
	}
	short_three_a(list_a);
}

void	short_three_b(t_head *head, t_node **list_b)
{
	t_node	*max;
	t_node	*min;

	if (!list_b || !*list_b || ft_is_short_b(head, *list_b))
	{
		ft_actualize_medium_b(head);
		ft_actualize_positions_and_axis_a(head->list_a, head);
		return ;
	}
	max = search_max(*list_b);
	min = search_min(*list_b);
	if (min == *list_b)
		r_b(list_b, 1);
	else if (min == (*list_b)->next)
	{
		swp_b(list_b, 1);
		r_b(list_b, 1);
	}
	else if (min == (*list_b)->next->next)
	{
		if (max == list_b[0]->next)
			swp_b(list_b, 1);
	}
	short_three_b(head, list_b);
}

void	short_five(t_head *head)
{
	if (!head || !head->list_a)
		return ;
	pb(head, &(head->list_a), &(head->list_b), 2);
	short_three_a(&(head->list_a));
	if (head->list_b->num < head->list_b->next->num)
		swp_b(&(head->list_b), 1);
	dump_nums_on_a(head);
}

void	short_big(t_head *head)
{
	int	i;

	if (!head)
		return ;
	i = 0;
	if (!ft_is_short(head->list_a))
	{
		pb(head, &(head->list_a), &(head->list_b), 3);
		short_three_b(head, &(head->list_b));
		while (head->stack_a_len > 3)
		{
			fix_medium_and_docks(head);
			make_budgets(head);
			do_moves(head);
			i++;
		}
		dump_nums_on_a(head);
	}
}
