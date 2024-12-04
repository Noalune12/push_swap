/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:18 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/04 17:57:05 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

int		check_args(int ac, char **av, t_node **stack_a);
void	push_stack(t_node **stack, int value);
void	swap_a_or_b(t_node **stack, char c, int ss);
void	swap_a_and_b(t_node **stack_a, t_node **stack_b);
void	push_on_top(t_node **stack_push, t_node **stack_pull, char c);
void	free_stack(t_node **stack);
void	rotate_a_or_b(t_node **stack, char c, int rr);
void	reverse_a_or_b(t_node **stack, char c, int rrr);
int		get_stack_size(t_node *stack);
void	print_stack(t_node *stack, char c);
void	sort_2(t_node **stack);
void	sort_3(t_node **stack_a);
int		is_sorted(t_node *stack);
void	sort_all(t_node **stack_a, t_node **stack_b);
// void	partition_lower(t_node **stack_a, t_node **stack_b, int pivot, int size);
// void	quick_sort(t_node **stack_a, t_node **stack_b, int low, int high);
void	push_min_up(t_node **stack_a);
void	sort_10(t_node **stack_a, t_node **stack_b);

#endif
