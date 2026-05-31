/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actualize_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:32:04 by alex              #+#    #+#             */
/*   Updated: 2026/05/31 14:15:38 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* @brief Actualizes the positions of the nodes in stack A and the axis A 
	in the head structure.
* @param list_a The circular linked list representing stack A.
* @param head The head structure containing metadata about the stacks.
* @return void
*/
void	ft_actualize_positions_and_axis_a(t_node *list_a, t_head *head)
{
	t_node	*current;
	int		i;
	int		a;

	if (!head || !list_a)
		return ;
	i = 1;
	current = list_a;
	while (current)
	{
		current->position = i;
		if (current->next == list_a)
			break ;
		current = current->next;
		i++;
	}
	a = 0;
	if (head->stack_a_len % 2 != 0)
		a = 1;
	head->axis_a = head->stack_a_len / 2 + a;
}

/**
* @brief Actualizes the medium node of stack B in the head structure.
* @param head The head structure containing metadata about the stacks.
* @return void
*/
void	ft_actualize_medium_b(t_head *head)
{
	t_node	*current_b;
	int		a;
	int		rest;
	int		limit;
	int		i;

	if (!head || !head->list_b)
		return ;
	a = head->stack_b_len / 2;
	rest = head->stack_b_len % 2;
	if (rest)
		limit = a + 1;
	else
		limit = a;
	i = 1;
	current_b = head->list_b;
	while (i < limit && current_b)
	{
		if (current_b->next == head->list_b)
			break ;
		current_b = current_b->next;
		i++;
	}
	head->medium_b = current_b;
}

/**
* @brief Actualizes the docks of stack B in the head structure based on the 
	current medium node and the length of stack B.
* @param head The head structure containing metadata about the stacks.
* @return void
*/
void	fix_medium_and_docks(t_head *head)
{
	int	i;

	if (!head || (!head->docks_b[1] && !head->docks_b[0]))
		return ;
	i = 1;
	if (head->stack_b_len % 2 == 0)
		i = 0;
	if (head->docks_b[0] && head->docks_b[0] >= (head->stack_b_len / 2 + i))
	{
		if (!(head->docks_b[0] == head->stack_b_len / 2 + i
				&& head->medium_b == search_max(head->list_b)))
		{
			head->docks_b[1] = head->stack_b_len - head->docks_b[0];
			head->docks_b[0] = 0;
		}
	}
	if (head->docks_b[1] && head->docks_b[1] >= (head->stack_b_len / 2 + i))
	{
		if (!(head->docks_b[1] == head->stack_b_len / 2 + i
				&& head->medium_b == search_min(head->list_b)))
		{
			head->docks_b[0] = head->stack_b_len - head->docks_b[1];
			head->docks_b[1] = 0;
		}
	}
}
