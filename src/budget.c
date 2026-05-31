/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   budget.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:54:44 by alex              #+#    #+#             */
/*   Updated: 2026/05/31 14:14:49 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* @brief Calculates the budget for each node in stack A, which represents the 
	cost of moving that node to the correct position in stack B.
* @param head The head structure containing metadata about the stacks.
* @return void
*/
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

/**
* @brief Calculates the budget for a specific node in stack A, which represents
	the cost of moving that node to the correct position in stack B, 
	considering the positions of the docks in stack B.
* @param head The head structure containing metadata about the stacks.
* @param node The node in stack A for which the budget is being calculated.
* @return void
*/
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

/**
* @brief Calculates the budget for a specific node in stack A, which represents
	the cost of moving that node to the correct position in stack B, 
	considering the positions of the docks in stack B when the top dock is 
	occupied.
* @param head The head structure containing metadata about the stacks.
* @param node The node in stack A for which the budget is being calculated.
* @return void
*/
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

/**
* @brief Calculates the budget for a specific node in stack A, which represents
	the cost of moving that node to the correct position in stack B, 
	considering the positions of the docks in stack B when the bottom dock is 
	occupied.
* @param head The head structure containing metadata about the stacks.
* @param node The node in stack A for which the budget is being calculated.
* @return void
*/
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
