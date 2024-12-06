/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:18 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/06 11:55:55 by lbuisson         ###   ########lyon.fr   */
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

int	check_error(int ac, char **av, t_node **stack_a);
void	push_stack(t_node **stack, int value);
void	free_stack(t_node **stack);
void	swap_a_or_b(t_node **stack, char c, int ss);
void	push_on_top(t_node **stack_push, t_node **stack_pull, char c);

#endif
