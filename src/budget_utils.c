/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   budget_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:06:29 by alex              #+#    #+#             */
/*   Updated: 2025/02/22 22:41:19 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hwm_on_topb(t_head *head, t_node *current, int delimiter, int counter)
{
	t_node	*list_b;
	int		i;

	if (!head || !current)
		return (0);
	list_b = head->list_b;
	i = 0;
	while (i < counter)
	{
		list_b = list_b->next;
		if (list_b->next == head->list_b)
			break ;
		i++;
	}
	while (list_b != head->medium_b && counter < delimiter)
	{
		if (current->num > list_b->num)
			break ;
		counter++;
		list_b = list_b->next;
	}
	return (counter);
}

int	hwm_on_lowerb(t_head *head, t_node *current, int delimiter, int counter)
{
	t_node	*list_b;
	int		i;

	if (!head || !current)
		return (0);
	list_b = head->list_b->prev;
	i = 0;
	while (i < counter)
	{
		list_b = list_b->prev;
		if (list_b->prev == head->list_b)
			break ;
		i++;
	}
	while (list_b != head->medium_b && counter < delimiter)
	{
		if (current->num < list_b->num)
			break ;
		counter++;
		list_b = list_b->prev;
	}
	return (counter);
}

int	calculate_cost_a(t_node *current, t_head *head)
{
	int		cost;
	int		position;
	int		i;

	if (!current || !head)
		return (0);
	position = current->position;
	i = 1;
	if (head->stack_a_len % 2 == 0)
		i = 0;
	if (position <= head->stack_a_len / 2 + i)
		cost = position - 1;
	else
		cost = head->stack_a_len - position + 1;
	return (cost);
}

int	check_sales(t_head *head, t_node *current, char flag)
{
	int		sales;
	int		min_cost;

	if (!head || !current)
		return (0);
	if (current->cost_a <= current->cost_b)
		min_cost = current->cost_a;
	else
		min_cost = current->cost_b;
	if (!flag)
	{
		if (current->position <= head->axis_a)
			sales = min_cost;
		else
			sales = 0;
	}
	else
	{
		if (current->position <= head->axis_a)
			sales = 0;
		else
			sales = min_cost;
	}
	return (sales);
}
