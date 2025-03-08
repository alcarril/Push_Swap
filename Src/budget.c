/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   budget.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:54:44 by alex              #+#    #+#             */
/*   Updated: 2025/02/23 17:59:34 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_budgets(t_head *head)
{
	t_node	*current;

	if (!head)
		return ;
	current = head->list_a;
	while (current)
	{
		if (head->docks_b[0] == 0 && head->docks_b[1] == 0)
			node_budget(head, current);
		else if (head->docks_b[0] != 0)
			node_budget_with_top_docks(head, current);
		else if (head->docks_b[1] != 0)
			node_budget_with_bottom_docks(head, current);
		if (current->next == head->list_a)
			break ;
		current = current->next;
	}
}

void	node_budget(t_head *head, t_node *node)
{
	int		medium;

	medium = head->medium_b->num;
	if (!head || !node)
		return ;
	node->cost_a = calculate_cost_a(node, head);
	if (node->num >= medium)
	{
		node->cost_b = hwm_on_topb(head, node, head->stack_b_len, 0);
		node->sales = check_sales(head, node, 0);
	}
	else
	{
		node->cost_b = hwm_on_lowerb(head, node, head->stack_b_len, 0);
		node->sales = check_sales(head, node, 1);
	}
	node->total_cost = node->cost_b + node->cost_a - node->sales + 1;
}

void	node_budget_with_top_docks(t_head *head, t_node *node)
{
	if (!head || !node)
		return ;
	node->cost_a = calculate_cost_a(node, head);
	if (node->num < head->medium_b->num && node->num < head->list_b->prev->num)
	{
		node->cost_b = hwm_on_topb(head, node, head->docks_b[0], 0);
		node->sales = check_sales(head, node, 0);
	}
	else if (node->num >= head->medium_b->num)
	{
		node->cost_b = hwm_on_topb(head, node, head->stack_b_len,
				head->docks_b[0]);
		node->sales = check_sales(head, node, 0);
	}
	else if (node->num < head->medium_b->num
		&& node->num > head->list_b->prev->num)
	{
		node->cost_b = hwm_on_lowerb(head, node, head->stack_b_len, 0);
		node->sales = check_sales(head, node, 1);
	}
	node->total_cost = node->cost_b + node->cost_a - node->sales + 1;
}

void	node_budget_with_bottom_docks(t_head *head, t_node *node)
{
	if (!head || !node)
		return ;
	node->cost_a = calculate_cost_a(node, head);
	if (node->num > head->medium_b->num && node->num < head->list_b->prev->num)
	{
		node->cost_b = hwm_on_topb(head, node, head->stack_b_len, 0);
		node->sales = check_sales(head, node, 0);
	}
	else if (node->num < head->medium_b->num)
	{
		node->cost_b = hwm_on_lowerb(head, node, head->stack_b_len,
				head->docks_b[1]);
		node->sales = check_sales(head, node, 1);
	}
	else if (node->num > head->medium_b->num
		&& node->num > head->list_b->prev->num)
	{
		node->cost_b = hwm_on_lowerb(head, node, head->docks_b[1], 0);
		node->sales = check_sales(head, node, 1);
	}
	node->total_cost = node->cost_b + node->cost_a - node->sales + 1;
}
