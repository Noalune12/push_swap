/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:43:31 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/03 08:43:32 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_or_b(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
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

void	rotate_a_and_b(t_node **stack_a, t_node **stack_b)
{
	rotate_a_or_b(stack_a);
	rotate_a_or_b(stack_b);
}

void	reverse_a_or_b(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
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
	reverse_a_or_b(stack_a);
	reverse_a_or_b(stack_b);
}
