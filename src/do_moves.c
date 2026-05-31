/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:04:23 by alex              #+#    #+#             */
/*   Updated: 2025/02/27 13:38:46 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_moves(t_head *head)
{
	t_node	*node;

	if (!head)
		return ;
	node = select_best_node_to_move(head);
	if (!node)
		return ;
	if (!head->docks_b[0] && !head->docks_b[1])
	{
		if (node->position <= head->axis_a)
			moves_on_top(head, node);
		else if (node->position > head->axis_a)
			moves_on_lower(head, node);
	}
	else if (head->docks_b[0] != 0 || head->docks_b[1] != 0)
	{
		rotate_b_cases(head, node, head->medium_b->num, node->num);
		rrotate_b_cases(head, node, head->medium_b->num, node->num);
	}
	pb(head, &(head->list_a), &(head->list_b), 1);
	ft_actualize_medium_b(head);
	ft_actualize_positions_and_axis_a(head->list_a, head);
}

void	moves_on_top(t_head *head, t_node *node)
{
	if (!head || !node)
		return ;
	r_ab(&(head->list_a), &(head->list_b), node->sales);
	r_a(&(head->list_a), node->cost_a - node->sales);
	if (node->num >= head->medium_b->num)
	{
		r_b(&(head->list_b), node->cost_b - node->sales);
		head->docks_b[1] = node->cost_b;
	}
	else
	{
		rr_b(&(head->list_b), node->cost_b);
		head->docks_b[0] = node->cost_b + 1;
		if (node->cost_b == 0)
			head->docks_b[0] = 1;
	}
}

void	moves_on_lower(t_head *head, t_node *node)
{
	if (!head || !node)
		return ;
	rr_ab(&(head->list_a), &(head->list_b), node->sales);
	rr_a(&(head->list_a), node->cost_a - node->sales);
	if (node->num >= head->medium_b->num)
	{
		r_b(&(head->list_b), node->cost_b);
		head->docks_b[1] = node->cost_b;
	}
	else
	{
		rr_b(&(head->list_b), node->cost_b - node->sales);
		head->docks_b[0] = node->cost_b + 1;
		if (node->cost_b == 0)
			head->docks_b[0] = 1;
	}
}

void	rotate_b_cases(t_head *head, t_node *node, int m_val, int num)
{
	if (!head || !node)
		return ;
	else if (head->docks_b[1] && num > m_val && num < head->list_b->prev->num)
	{
		head->docks_b[1] = head->docks_b[1] + node->cost_b;
		head->docks_b[0] = 0;
		handle_position_r(head, node);
	}
	if (head->docks_b[0] && num < m_val && num < head->list_b->prev->num)
	{
		head->docks_b[0] = head->docks_b[0] - node->cost_b + 1;
		head->docks_b[1] = 0;
		handle_position_r(head, node);
	}
	else if (head->docks_b[0] && num > m_val)
	{
		head->docks_b[1] = node->cost_b - head->docks_b[0];
		head->docks_b[0] = 0;
		handle_position_r(head, node);
	}
}

void	rrotate_b_cases(t_head *head, t_node *node, int m_val, int num)
{
	if (!head || !node)
		return ;
	if (head->docks_b[0] && num < m_val && num > head->list_b->prev->num)
	{
		head->docks_b[0] = node->cost_b + head->docks_b[0] + 1;
		head->docks_b[1] = 0;
		handle_position_rr(head, node);
	}
	else if (head->docks_b[1] && num > m_val && num > head->list_b->prev->num)
	{
		head->docks_b[1] = head->docks_b[1] - node->cost_b;
		head->docks_b[0] = 0;
		handle_position_rr(head, node);
	}
	else if (head->docks_b[1] && num < m_val)
	{
		head->docks_b[0] = node->cost_b - head->docks_b[1] + 1;
		head->docks_b[1] = 0;
		handle_position_rr(head, node);
	}
}
