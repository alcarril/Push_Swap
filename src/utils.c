/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:46:16 by alex              #+#    #+#             */
/*   Updated: 2026/05/31 14:28:19 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if the circular linked list representing stack A is already sorted
 * in ascending order. It iterates through the list and compares each node's value
 * with the next node's value to determine if the list is sorted.
 * @param list_a The circular linked list representing stack A.
 * @return A character value (1 if the list is sorted, 0 if it is not).
 */
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

/**
 * @brief Checks if the circular linked list representing stack B is already sorted
 * in descending order. It iterates through the list and compares each node's value
 * with the next node's value to determine if the list is sorted.
 * @param head The head structure containing metadata about the stacks.
 * @param list_b The circular linked list representing stack B.
 * @return A character value (1 if the list is sorted, 0 if it is not).
 */
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

/**
 * @brief Searches for the node with the maximum value in a circular linked list.
 * It iterates through the list and compares each node's value to find the maximum.
 * @param list The circular linked list to be searched.
 * @return A pointer to the node with the maximum value, or NULL if the list is empty.
 */
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

/**
 * @brief Searches for the node with the minimum value in a circular linked list.
 * It iterates through the list and compares each node's value to find the minimum.
 * @param list The circular linked list to be searched.
 * @return A pointer to the node with the minimum value, or NULL if the list is empty.
 */
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

/**
 * @brief Prints an error message to standard error and exits the program.
 * @param message The error message to print.
 */
void	ft_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(0);
}
