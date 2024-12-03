/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:18 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/03 07:31:23 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_node
{
	int		value;
	void	*prev;
	void	*next;
}	t_node;

int		check_args(int ac, char **av);
void	swap_a_or_b(t_node **stack);
void	swap_a_and_b(t_node **stack_a, t_node **stack_b);
void	push_on_top(t_node **stack_push, t_node **stack_pull);
void	free_stack(t_node **stack);
void	rotate_a_or_b(t_node **stack);
void	reverse_a_or_b(t_node **stack);

#endif
