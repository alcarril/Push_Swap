/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:25:55 by alex              #+#    #+#             */
/*   Updated: 2026/05/31 14:14:01 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* @brief Selects the node in stack A with the lowest total cost to move to 
	stack B, and in case of a tie, selects the node with the lower number.
* @param head The head structure containing metadata about the stacks.
* @return A pointer to the node in stack A that has the lowest total cost to
	move to stack B.
*/
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

/**
* @brief Calculates the budget for a specific node in stack A, which represents
	the cost of moving that node to the correct position in stack B, 
	considering the positions of the docks in stack B when both docks are 
	occupied.
* @param head The head structure containing metadata about the stacks.
* @param node The node in stack A for which the budget is being calculated.
* @return void
*/
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

/**
* @brief Calculates the budget for a specific node in stack A, which represents
	the cost of moving that node to the correct position in stack B, 
	considering the positions of the docks in stack B when both docks are 
	occupied.
* @param head The head structure containing metadata about the stacks.
* @param node The node in stack A for which the budget is being calculated.
* @return void
*/
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

/**
* @brief Moves all the numbers from stack B back to stack A in the correct 
	order, after all the nodes have been moved from stack A to stack B.
* @param head The head structure containing metadata about the stacks.
* @return void
*/
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

/**
* @brief Moves numbers from stack B back to stack A until the current number in
	stack A is lower than the current number in stack B, ensuring that the 
	numbers are moved back to stack A in the correct order.
* @param head The head structure containing metadata about the stacks.
* @param current_a The current node in stack A that is being compared to the 
	current node in stack B.
* @return void
*/
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
