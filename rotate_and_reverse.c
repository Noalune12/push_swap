/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:43:31 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/04 17:50:33 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_printf/ft_printf.h"

void	rotate_a_or_b(t_node **stack, char c, int rr)
{
	t_node	*temp;
	t_node	*temp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if (c == 'a' && rr == 0)
		ft_printf("ra\n");
	else if (c == 'b' && rr == 0)
		ft_printf("rb\n");
	temp = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	temp2 = (*stack);
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp;
	temp->prev = temp2;
	temp->next = NULL;
}

void	rotate_a_and_b(t_node **stack_a, t_node **stack_b, int rr)
{
	ft_printf("rr\n");
	rotate_a_or_b(stack_a, 'a', 1);
	rotate_a_or_b(stack_b, 'b', 1);
}

void	reverse_a_or_b(t_node **stack, char c, int rrr)
{
	t_node	*temp;
	t_node	*temp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if (c == 'a' && rrr == 0)
		ft_printf("rra\n");
	else if (c == 'b' && rrr == 0)
		ft_printf("rrb\n");
	temp = (*stack);
	while (temp->next)
		temp = temp->next;
	temp2 = (*stack);
	(*stack) = temp;
	temp2->prev = (*stack);
	temp = temp->prev;
	(*stack)->prev = NULL;
	(*stack)->next = temp2;
	temp->next = NULL;
}

void	reverse_a_and_b(t_node **stack_a, t_node **stack_b)
{
	ft_printf("rrr\n");
	reverse_a_or_b(stack_a, 'a', 1);
	reverse_a_or_b(stack_b, 'b', 1);
}
