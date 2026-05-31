/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:53:15 by alex              #+#    #+#             */
/*   Updated: 2026/05/31 14:21:36 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Executes the necessary moves to rotate stack A to the right,
 * and writes the appropriate move command to the standard output as it executes the move.
 * @param list_a The circular linked list representing stack A.
 * @param limit The maximum number of moves to execute.
 * @return void
 */
void	rr_a(t_node **list_a, int limit)
{
	static int	counter;

	if (!list_a || !*list_a || counter >= limit)
	{
		counter = 0;
		return ;
	}
	list_a[0] = list_a[0]->prev;
	write(1, "rra\n", 4);
	counter++;
	rr_a(list_a, limit);
}

/**
 * @brief Executes the necessary moves to rotate stack B to the right,
 * and writes the appropriate move command to the standard output as it 
 * executes the move.
 * @param list_b The circular linked list representing stack B.
 * @param limit The maximum number of moves to execute.
 * @return void
 */
void	rr_b(t_node **list_b, int limit)
{
	static int	counter;

	if (!list_b || !*list_b || counter >= limit)
	{
		counter = 0;
		return ;
	}
	list_b[0] = list_b[0]->prev;
	write(1, "rrb\n", 4);
	counter++;
	rr_b(list_b, limit);
}

/**
 * @brief Executes the necessary moves to rotate stack A to the left,
 * and writes the appropriate move command to the standard output as 
 * it executes the move.
 * @param list_a The circular linked list representing stack A.
 * @param limit The maximum number of moves to execute.
 * @return void
 */
void	r_a(t_node **list_a, int limit)
{
	static int	counter;

	if (!list_a || !*list_a || counter >= limit)
	{
		counter = 0;
		return ;
	}
	list_a[0] = list_a[0]->next;
	write(1, "ra\n", 3);
	counter++;
	r_a(list_a, limit);
}

/**
 * @brief Executes the necessary moves to rotate stack B to the left,
 * and writes the appropriate move command to the standard output as 
 * it executes the move.
 * @param list_b The circular linked list representing stack B.
 * @param limit The maximum number of moves to execute.
 * @return void
 */
void	r_b(t_node **list_b, int limit)
{
	static int	counter;

	if (!list_b || !*list_b || counter >= limit)
	{
		counter = 0;
		return ;
	}
	list_b[0] = list_b[0]->next;
	write(1, "rb\n", 3);
	counter++;
	r_b(list_b, limit);
}

/**
 * @brief Executes the necessary moves to rotate both stack A and stack B to 
 * the right, and writes the appropriate move command to the standard 
 * output as it executes the move.
 * @param list_a The circular linked list representing stack A.
 * @param list_b The circular linked list representing stack B.
 * @param limit The maximum number of moves to execute.
 * @return void
 */
void	rr_ab(t_node **list_a, t_node **list_b, int limit)
{
	static int	counter;

	if (!*list_a || !*list_b)
		return ;
	if (!list_a || !list_b || counter >= limit)
	{
		counter = 0;
		return ;
	}
	list_a[0] = list_a[0]->prev;
	list_b[0] = list_b[0]->prev;
	write(1, "rrr\n", 4);
	counter++;
	rr_ab(list_a, list_b, limit);
}
