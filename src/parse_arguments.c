/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:52:23 by alex              #+#    #+#             */
/*   Updated: 2026/05/31 14:24:10 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Parses the command line arguments, checks for validity, and loads the
 * initial data into the head structure, which contains metadata about the stacks.
 * @param arguments The command line arguments passed to the program.
 * @return A pointer to the head structure containing the initial data for the 
 * stacks.
 */
t_head	*set_data(char **arguments)
{
	t_head	*head;
	char	**table_arguments;
	int		i;

	i = 1;
	head = NULL;
	while (arguments[i] != NULL)
	{
		table_arguments = parse_string_and_split(arguments[i]);
		if (!table_arguments)
		{
			ft_error("Error\n");
		}
		head = check_and_load(table_arguments, 0);
		if (!head)
		{
			ft_free_table(table_arguments);
			ft_error("Error\n");
		}
		ft_free_table(table_arguments);
		i++;
	}
	return (head);
}

/**
 * @brief Checks the validity of the parsed arguments and loads them into 
 * the head structure. It verifies that each argument is a valid integer, 
 * checks for duplicates, and ensures the values are within the valid range.
 * @param args The array of strings representing the parsed arguments.
 * @param flag A flag indicating whether to skip the first argument (used when
 * parsing a single string of arguments).
 * @return A pointer to the head structure containing the loaded data, or NULL 
 * if any argument is invalid.
 */
t_head	*check_and_load(char **args, char flag)
{
	static t_head	*head;
	int				i;
	int				j;

	i = -1;
	while (args[++i])
	{
		if (flag && i == 0)
			i++;
		j = -1;
		while (args[i][++j])
		{
			if (!ft_isdigit(args[i][j]) && !(j == 0 && args[i][j] == '-'
				&& args[i][j + 1] != '\0'))
			{
				return (NULL);
			}
		}
		head = check_and_load_aux(ft_atolong(args[i]));
		if (!head)
			return (NULL);
	}
	return (head);
}

/**
 * @brief Checks if a given number is a duplicate in stack A. It iterates through
 * the circular linked list representing stack A and compares each node's value
 * with the given number.
 * @param num The number to be checked for duplication.
 * @param stack_a The circular linked list representing stack A.
 * @return 1 if the number is a duplicate, 0 otherwise.
 */
char	ft_isduplicate(int num, t_node *stack_a)
{
	t_node	*aux;

	if (!stack_a)
		return (0);
	aux = stack_a;
	while (aux)
	{
		if (aux->num == num)
			return (1);
		if (aux->next == stack_a)
			break ;
		aux = aux->next;
	}
	return (0);
}

/**
 * @brief Checks the validity of a single argument, converts it to a long 
 * integer,and loads it into the head structure if it's valid. It ensures 
 * that the number is within the valid range and not a duplicate in stack A.
 * @param n The long integer representation of the argument to be checked and 
 * loaded.
 * @return A pointer to the head structure containing the loaded data, or 
 * NULL if the argument is invalid.
 */
t_head	*check_and_load_aux(long n)
{
	static int		position;
	static t_head	*head;
	t_node			*new;

	if (!head)
	{
		head = (t_head *)malloc(sizeof(t_head) * 1);
		if (!head)
			return (NULL);
		load_head(head);
	}
	if ((n > INT_MAX || n < INT_MIN) || ft_isduplicate(n, head->list_a))
	{
		return (NULL);
	}
	else
	{
		new = ft_lstnew_ps((int)n);
		new->position = position++;
		ft_lstaddback_ps(&(head->list_a), new);
		head->stack_a_len++;
		return (head);
	}
}

/**
 * @brief Parses a single string of arguments, splits it into individual arguments,
 * and checks for validity. It uses the ft_split function to split the string by
 * spaces and ensures that the resulting arguments are valid before returning them.
 * @param string The single string containing all the arguments to be parsed and 
 * split.
 * @return An array of strings representing the individual arguments, or NULL if
 * the string is empty or if the splitting fails.
 */
char	**parse_string_and_split(char *string)
{
	char	**arguments;

	arguments = ft_split(string, ' ');
	if (arguments && !arguments[0])
	{
		ft_free_table(arguments);
		return (NULL);
	}
	if (!arguments)
	{
		return (NULL);
	}
	return (arguments);
}
