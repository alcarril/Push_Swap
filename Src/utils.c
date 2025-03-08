/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:46:16 by alex              #+#    #+#             */
/*   Updated: 2025/02/27 13:39:27 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_is_short(t_node *list_a)
{
	t_node	*current;

	if (list_a == NULL)
		return (0);
	if (list_a->next == list_a)
		return (1);
	current = list_a;
	while (current)
	{
		if (current->next == list_a)
			break ;
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

char	ft_is_short_b(t_head *head, t_node *list_b)
{
	t_node	*current;

	if (list_b == NULL || head == NULL)
		return (0);
	if (list_b->next == list_b)
		return (1);
	current = list_b;
	while (current->next != list_b)
	{
		if (current->num < current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

t_node	*search_max(t_node *list)
{
	t_node	*max;
	t_node	*current;

	if (!list)
		return (NULL);
	current = list;
	max = current;
	while (current)
	{
		if (current->num >= max->num)
			max = current;
		if (current->next == list)
			break ;
		current = current->next;
	}
	return (max);
}

t_node	*search_min(t_node *list)
{
	t_node	*min;
	t_node	*current;

	if (!list)
		return (NULL);
	current = list;
	min = list;
	while (current)
	{
		if (current->num <= min->num)
			min = current;
		if (current->next == list)
			break ;
		current = current->next;
	}
	return (min);
}

void	ft_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(0);
}
