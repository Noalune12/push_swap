/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:18 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/05 12:35:31 by lbuisson         ###   ########lyon.fr   */
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

int		check_error(int ac, char **av, t_node **stack_a);
void	free_stack(t_node **stack);
void	push_stack(t_node **stack, int value);
int		get_stack_size(t_node *stack); //utils ??
void	sort_2(t_node **stack);
void	sort_3(t_node **stack_a);
void	sort_10(t_node **stack_a, t_node **stack_b, int algo);
int		is_sorted(t_node *stack); //utils ??
void	rotate_a_or_b(t_node **stack, char c, int rr);
void	reverse_a_or_b(t_node **stack, char c, int rrr);
void	swap_a_or_b(t_node **stack, char c, int ss);
void	push_on_top(t_node **stack_push, t_node **stack_pull, char c);

//remove after finishing project
void	print_stack(t_node *stack, char c);

#endif
