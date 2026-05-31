/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:08:39 by alex              #+#    #+#             */
/*   Updated: 2026/05/31 14:24:39 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief The main function of the push_swap program. It parses the command line
 * arguments, checks for validity, loads the initial data into the head structure,
 * and executes the necessary moves to sort the numbers in stack A using stack B as
 * an auxiliary stack. It also handles the case of sorting a small number of elements
 * with a specific sorting algorithm.
 * @param argz The number of command line arguments passed to the program.
 * @param argv The array of strings representing the command line arguments.
 * @return An integer representing the exit status of the program (0 for success, 1
 * for failure).
 */
int	main(int argz, char **argv)
{
	t_head	*head;

	if (argz < 2)
		return (1);
	head = set_data(argv);
	if (!head)
		return (1);
	short_nums(head);
	return (0);
}
