/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:39:49 by alex              #+#    #+#             */
/*   Updated: 2025/02/28 17:58:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Include/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	int				position;
	int				cost_b;
	int				cost_a;
	int				sales;
	int				total_cost;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_head
{
	int				stack_a_len;
	int				stack_b_len;
	int				docks_b[2];
	int				axis_a;
	struct s_node	*medium_b;
	struct s_node	*list_b;
	struct s_node	*list_a;
}					t_head;

/////////Prototipes///////

// Main
void				print_stack_numbers(t_head *head);
void				print_head_and_stacks(t_head *head);
// Parsing args
char				**parse_string_and_split(char *string);
char				ft_isduplicate(int num, t_node *stack_a);
t_head				*set_data(char **arguments);
t_head				*check_and_load(char **args, char flag);
t_head				*check_and_load_aux(long n);

// nodes
t_node				*ft_lstnew_ps(int num);
void				ft_lstaddback_ps(t_node **list, t_node *new);
void				load_head(t_head *head);
void				i_nul(t_head *head);
void				ft_free_stacks(t_head *head);

// Moves
void				rr_a(t_node **list_a, int limit);
void				rr_b(t_node **list_b, int limit);
void				rr_ab(t_node **list_a, t_node **list_b, int limit);
void				r_a(t_node **list_a, int limit);
void				r_b(t_node **list_b, int limit);
void				r_ab(t_node **list_a, t_node **list_b, int limit);
void				swp_a(t_node **list_a, int limit);
void				swp_b(t_node **list_b, int limit);
void				pa(t_head *head, t_node **list_a, t_node **list_b,
						int limit);
void				pb(t_head *head, t_node **list_a, t_node **list_b,
						int limit);

// Updates and utils: (positions, cost)
t_node				*search_max(t_node *list);
t_node				*search_min(t_node *list);
void				ft_error(char *message);
char				ft_is_short(t_node *list_a);
char				ft_is_short_b(t_head *head, t_node *list_b);
void				ft_actualize_positions_and_axis_a(t_node *list_a,
						t_head *head);
void				ft_actualize_medium_b(t_head *head);

// Short
void				short_nums(t_head *head);
void				short_three_a(t_node **list_a);
void				short_three_b(t_head *head, t_node **list_b);
void				short_five(t_head *head);
void				short_big(t_head *head);
void				dump_nums_on_a(t_head *head);
void				dump_until_lower(t_head *head, t_node *current_a);

// budgeting
void				make_budgets(t_head *head);
void				node_budget(t_head *head, t_node *node);
void				node_budget_with_bottom_docks(t_head *head, t_node *node);
void				node_budget_with_top_docks(t_head *head, t_node *node);
int					hwm_on_topb(t_head *head, t_node *current, int delimiter,
						int counter);
int					hwm_on_lowerb(t_head *head, t_node *current, int delimiter,
						int counter);
int					check_sales(t_head *head, t_node *current, char flag);
int					calculate_cost_a(t_node *current, t_head *head);

// do_moves
t_node				*select_best_node_to_move(t_head *head);
void				fix_medium_and_docks(t_head *head);
void				do_moves(t_head *head);
void				moves_on_top(t_head *head, t_node *node);
void				moves_on_lower(t_head *head, t_node *node);
void				rotate_b_cases(t_head *head, t_node *node, int m_val,
						int num);
void				rrotate_b_cases(t_head *head, t_node *node, int m_val,
						int num);
void				handle_position_r(t_head *head, t_node *node);
void				handle_position_rr(t_head *head, t_node *node);

#endif