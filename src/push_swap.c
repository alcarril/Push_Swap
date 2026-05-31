/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarril <alcarril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:08:39 by alex              #+#    #+#             */
/*   Updated: 2025/03/08 19:45:06 by alcarril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
