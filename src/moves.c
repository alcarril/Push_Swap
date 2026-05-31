/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:02:51 by alex              #+#    #+#             */
/*   Updated: 2026/05/31 14:20:02 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Executes the necessary moves to transfer the selected node from stack A
 * to stack B, ensuring that the node is moved to the correct position in stack B
 * according to its value and the current state of stack B. Writes the appropriate
 * move commands to the standard output as it executes the moves.
 * @param head The head structure containing metadata about the stacks.
 * @return void
 */
void	r_ab(t_node **list_a, t_node **list_b, int limit)
{
	static int	count;

	if (!*list_a || !*list_b)
		return ;
	if (count >= limit || !list_a || !list_b)
	{
		count = 0;
		return ;
	}
	count++;
	list_a[0] = list_a[0]->next;
	list_b[0] = list_b[0]->next;
	write(1, "rr\n", 3);
	r_ab(list_a, list_b, limit);
}

/**
 * @brief Executes the necessary moves to swap the top two nodes of stack A, 
 * and writes the appropriate move command to de stdout as it executes the move.
 * @param list_a The circular linked list representing stack A.
 * @param list_b The circular linked list representing stack B.
 * @param limit The maximum number of moves to execute.
 * @return void
 */
void	swp_a(t_node **list_a, int limit)
{
	static int	count;
	t_node		*aux;

	if (!list_a || !*list_a || count >= limit)
	{
		count = 0;
		return ;
	}
	if (list_a[0]->next->next == list_a[0])
		list_a[0] = list_a[0]->next;
	else
	{
		aux = list_a[0]->next;
		list_a[0]->next = list_a[0]->next->next;
		aux->next = list_a[0];
		aux->prev = list_a[0]->prev;
		list_a[0]->prev->next = aux;
		list_a[0]->prev = aux;
		list_a[0]->next->prev = list_a[0];
		list_a[0] = aux;
	}
	write(1, "sa\n", 3);
	count++;
	swp_a(list_a, limit);
}

/**
 * @brief Executes the necessary moves to swap the top two nodes of stack B, 
 * and writes the appropriate move command to de stdout as it executes the move.
 * @param list_b The circular linked list representing stack B.
 * @param limit The maximum number of moves to execute.
 * @return void
 */
void	swp_b(t_node **list_b, int limit)
{
	static int	count;
	t_node		*aux;

	if (!list_b || !*list_b || count >= limit)
	{
		count = 0;
		return ;
	}
	if (list_b[0]->next->next == list_b[0])
		list_b[0] = list_b[0]->next;
	else
	{
		aux = list_b[0]->next;
		list_b[0]->next = list_b[0]->next->next;
		aux->next = list_b[0];
		aux->prev = list_b[0]->prev;
		list_b[0]->prev->next = aux;
		list_b[0]->prev = aux;
		list_b[0]->next->prev = list_b[0];
		list_b[0] = aux;
	}
	write(1, "sb\n", 3);
	count++;
	swp_b(list_b, limit);
}

/**
 * @brief Executes the necessary moves to transfer the top node from stack A to stack B,
 * and writes the appropriate move command to the standard output as it executes the move.
 * @param head The head structure containing metadata about the stacks.
 * @param list_a The circular linked list representing stack A.
 * @param list_b The circular linked list representing stack B.
 * @param limit The maximum number of moves to execute.
 * @return void
 */
void	pb(t_head *head, t_node **list_a, t_node **list_b, int limit)
{
	static int	count;
	t_node		*aux_a;

	if (count++ >= limit || !head || !list_b || !list_a || !*list_a)
	{
		count = 0;
		return ;
	}
	aux_a = list_a[0];
	list_a[0]->prev->next = list_a[0]->next;
	list_a[0]->next->prev = list_a[0]->prev;
	list_a[0] = list_a[0]->next;
	if (*list_b)
	{
		aux_a->prev = list_b[0]->prev;
		list_b[0]->prev->next = aux_a;
		aux_a->next = list_b[0];
		list_b[0]->prev = aux_a;
		list_b[0] = aux_a;
	}
	else
		ft_lstaddback_ps(&(head->list_b), aux_a);
	head->stack_a_len--;
	head->stack_b_len++;
	return (write(1, "pb\n", 3), pb(head, list_a, list_b, limit));
}

/**
 * @brief Executes the necessary moves to transfer the top node from stack B to stack A,
 * and writes the appropriate move command to the standard output as it executes the move.
 * @param head The head structure containing metadata about the stacks.
 * @param list_a The circular linked list representing stack A.
 * @param list_b The circular linked list representing stack B.
 * @param limit The maximum number of moves to execute.
 * @return void
 */
void	pa(t_head *head, t_node **list_a, t_node **list_b, int limit)
{
	static int	count;
	t_node		*aux_b;

	if (count++ >= limit || !head || !*list_b)
	{
		count = 0;
		return ;
	}
	aux_b = list_b[0];
	list_b[0]->prev->next = list_b[0]->next;
	list_b[0]->next->prev = list_b[0]->prev;
	list_b[0] = list_b[0]->next;
	if (*list_a)
	{
		aux_b->prev = list_a[0]->prev;
		list_a[0]->prev->next = aux_b;
		aux_b->next = list_a[0];
		list_a[0]->prev = aux_b;
		list_a[0] = aux_b;
	}
	else
		ft_lstaddback_ps(&(head->list_a), aux_b);
	head->stack_a_len++;
	head->stack_b_len--;
	return (i_nul(head), write(1, "pa\n", 3), pa(head, list_a, list_b, limit));
}
