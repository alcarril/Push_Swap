/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_buffer_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarril <alcarril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:06:44 by alex              #+#    #+#             */
/*   Updated: 2025/03/08 19:35:37 by alcarril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew_ps(int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_lstaddback_ps(t_node **list, t_node *new)
{
	t_node	*current_node;

	if (!list || !new)
		return ;
	if (*list == NULL)
	{
		*list = new;
		new->next = *list;
		new->prev = *list;
		return ;
	}
	current_node = *list;
	while (current_node)
	{
		if (current_node->next == *list)
		{
			current_node->next = new;
			new->next = list[0];
			new->prev = current_node;
			list[0]->prev = new;
			break ;
		}
		current_node = current_node->next;
	}
}

void	ft_free_stacks(t_head *head)
{
	t_node	*aux;
	t_node	*current_a;
	t_node	*current_b;

	if (!head)
		return ;
	current_a = head->list_a;
	current_b = head->list_b;
	while (head->list_a)
	{
		aux = current_a;
		free(aux);
		if (current_a->next == head->list_a)
			break ;
		current_a = current_a->next;
	}
	while (head->list_b)
	{
		aux = current_b;
		free(aux);
		if (current_b->next == head->list_b)
			break ;
		current_b = current_b->next;
	}
	free(head);
}

void	load_head(t_head *head)
{
	if (!head)
		return ;
	head->list_a = NULL;
	head->list_b = NULL;
	head->medium_b = NULL;
	head->stack_a_len = 0;
	head->stack_b_len = 0;
	head->docks_b[0] = 0;
	head->docks_b[1] = 0;
}

void	i_nul(t_head *head)
{
	if (!head || !head->list_b)
		return ;
	if (head->stack_b_len == 0)
		head->list_b = NULL;
}
