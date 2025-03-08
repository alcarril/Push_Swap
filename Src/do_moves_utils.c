/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:25:55 by alex              #+#    #+#             */
/*   Updated: 2025/02/28 16:07:28 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*select_best_node_to_move(t_head *head)
{
	t_node	*cheapest;
	t_node	*current;

	if (!head || !head->list_a)
		return (NULL);
	current = head->list_a;
	cheapest = current;
	while (current)
	{
		if (current->total_cost < cheapest->total_cost)
			cheapest = current;
		else if (current->total_cost == cheapest->total_cost
			&& cheapest->num > current->num)
		{
			cheapest = current;
		}
		if (current->next == head->list_a)
			break ;
		current = current->next;
	}
	return (cheapest);
}

void	handle_position_r(t_head *head, t_node *node)
{
	if (!head || !node)
		return ;
	if (node->position <= head->axis_a)
	{
		r_ab(&(head->list_a), &(head->list_b), node->sales);
		r_a(&(head->list_a), node->cost_a - node->sales);
		r_b(&(head->list_b), node->cost_b - node->sales);
	}
	if (node->position > head->axis_a)
	{
		rr_a(&(head->list_a), node->cost_a);
		r_b(&(head->list_b), node->cost_b);
	}
}

void	handle_position_rr(t_head *head, t_node *node)
{
	if (!head || !node)
		return ;
	if (node->position <= head->axis_a)
	{
		r_a(&(head->list_a), node->cost_a);
		rr_b(&(head->list_b), node->cost_b);
	}
	if (node->position > head->axis_a)
	{
		rr_ab(&(head->list_a), &(head->list_b), node->sales);
		rr_a(&(head->list_a), node->cost_a - node->sales);
		rr_b(&(head->list_b), node->cost_b - node->sales);
	}
}

void	dump_nums_on_a(t_head *head)
{
	t_node	*current_a;
	int		limit;

	if (!head || !head->list_a || !head->list_b)
		return ;
	r_b(&(head->list_b), head->docks_b[0]);
	rr_b(&(head->list_b), head->docks_b[1]);
	if (!ft_is_short(head->list_a))
		short_nums(head);
	current_a = head->list_a->prev;
	limit = head->stack_a_len;
	while (limit > 0 && current_a)
	{
		dump_until_lower(head, current_a);
		current_a = head->list_a->prev;
		limit--;
	}
	if (head->stack_b_len)
		pa(head, &(head->list_a), &(head->list_b), head->stack_b_len);
}

void	dump_until_lower(t_head *head, t_node *current_a)
{
	t_node	*current_b;

	if (!head || !current_a)
		return ;
	current_b = head->list_b;
	while (current_b)
	{
		if (current_a->num < current_b->num)
			pa(head, &(head->list_a), &(head->list_b), 1);
		else
			break ;
		if (current_b->next == head->list_b)
			break ;
		current_b = head->list_b;
	}
	rr_a(&(head->list_a), 1);
}
