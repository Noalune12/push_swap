/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:18 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/06 16:00:47 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

int		check_error(int ac, char **av, t_node **stack_a);
void	push_stack(t_node **stack, int value);
void	swap_a_or_b(t_node **stack, char c, int ss);
void	push_on_top(t_node **stack_push, t_node **stack_pull, char c);
void	rotate_a_or_b(t_node **stack, char c, int rr);
void	reverse_a_or_b(t_node **stack, char c, int rrr);
void	update_index(t_node **stack);
void	sort_3(t_node **stack_a);
void	sort_2(t_node **stack);
void	sort_100(t_node **stack_a, t_node **stack_b);
int		get_stack_size(t_node *stack);

#endif
