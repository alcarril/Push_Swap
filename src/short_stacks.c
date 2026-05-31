/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:05:51 by alex              #+#    #+#             */
/*   Updated: 2026/05/31 14:26:51 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts a small number of elements in stack A using specific algorithms
 * based on the number of elements. It handles cases for 2, 3, 5, and more than 
 * 3 elements with different sorting strategies.
 * @param head The head structure containing metadata about the stacks.
 * @return void
 */
void	short_nums(t_head *head)
{
	if (!head || !head->list_a)
		return ;
	if (head->stack_a_len < 3)
	{
		if (head->list_a->next == head->list_a)
			return ;
		else if (head->list_a->num > head->list_a->next->num)
			swp_a(&(head->list_a), 1);
	}
	else if (head->stack_a_len == 3)
		short_three_a(&(head->list_a));
	else if (head->stack_a_len == 5)
		short_five(head);
	else if (head->stack_a_len > 3 && head->stack_a_len != 5)
		short_big(head);
}

/**
 * @brief Sorts three elements in stack A using a specific algorithm that
 * identifies the maximum and minimum elements and performs the necessary 
 * moves to sort them in ascending order.
 * @param list_a The circular linked list representing stack A.
 * @return void
 */
void	short_three_a(t_node **list_a)
{
	t_node	*max;
	t_node	*min;

	if (!list_a || !*list_a || ft_is_short(*list_a))
		return ;
	max = search_max(*list_a);
	min = search_min(*list_a);
	if (max == *list_a)
		r_a(list_a, 1);
	else if (max == (*list_a)->next)
	{
		swp_a(list_a, 1);
		r_a(list_a, 1);
	}
	else if (max == (*list_a)->next->next)
	{
		if (min == list_a[0]->next)
			swp_a(list_a, 1);
	}
	short_three_a(list_a);
}

/**
 * @brief Sorts three elements in stack B using a specific algorithm that
 * identifies the maximum and minimum elements and performs the necessary
 * moves to sort them in descending order, as stack B is used as an auxiliary
 * stack for sorting stack A.
 * @param head The head structure containing metadata about the stacks.
 * @param list_b The circular linked list representing stack B.
 * @return void
 */
void	short_three_b(t_head *head, t_node **list_b)
{
	t_node	*max;
	t_node	*min;

	if (!list_b || !*list_b || ft_is_short_b(head, *list_b))
	{
		ft_actualize_medium_b(head);
		ft_actualize_positions_and_axis_a(head->list_a, head);
		return ;
	}
	max = search_max(*list_b);
	min = search_min(*list_b);
	if (min == *list_b)
		r_b(list_b, 1);
	else if (min == (*list_b)->next)
	{
		swp_b(list_b, 1);
		r_b(list_b, 1);
	}
	else if (min == (*list_b)->next->next)
	{
		if (max == list_b[0]->next)
			swp_b(list_b, 1);
	}
	short_three_b(head, list_b);
}

/**
 * @brief Sorts five elements in stack A by first moving two elements to stack B,
 * sorting the three remaining elements in stack A, and then moving the two elements
 * back to stack A in the correct order. It uses the short_three_a and short_three_b
 * functions to sort the respective stacks and ensures that the final order in stack A
 * is correct.
 * @param head The head structure containing metadata about the stacks.
 * @return void
 */
void	short_five(t_head *head)
{
	if (!head || !head->list_a)
		return ;
	pb(head, &(head->list_a), &(head->list_b), 2);
	short_three_a(&(head->list_a));
	if (head->list_b->num < head->list_b->next->num)
		swp_b(&(head->list_b), 1);
	dump_nums_on_a(head);
}

/**
 * @brief Sorts a larger number of elements in stack A by first moving a portion of the
 * elements to stack B, sorting the remaining elements in stack A, and then moving the
 * elements back to stack A in the correct order. It uses the short_three_b function to
 * sort the elements in stack B and ensures that the final order in stack A is correct by
 * using the dump_nums_on_a function to move the elements back to stack A in the correct 
 * order.
 * @param head The head structure containing metadata about the stacks.
 * @return void
 */
void	short_big(t_head *head)
{
	int	i;

	if (!head)
		return ;
	i = 0;
	if (!ft_is_short(head->list_a))
	{
		pb(head, &(head->list_a), &(head->list_b), 3);
		short_three_b(head, &(head->list_b));
		while (head->stack_a_len > 3)
		{
			fix_medium_and_docks(head);
			make_budgets(head);
			do_moves(head);
			i++;
		}
		dump_nums_on_a(head);
	}
}
