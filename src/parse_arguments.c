/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarril <alcarril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:52:23 by alex              #+#    #+#             */
/*   Updated: 2025/03/08 19:45:01 by alcarril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
