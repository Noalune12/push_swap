/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:43:02 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/03 11:26:15 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_printf/ft_printf.h"

void	swap_a_or_b(t_node **stack) //simplify ??
{
	int		temp;
	t_node	*temp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	ft_printf("sa or sb\n");
	temp = (*stack)->value;
	temp2 = (*stack)->next;
	(*stack)->value = temp2->value;
	temp2->value = temp;
}

void	swap_a_and_b(t_node **stack_a, t_node **stack_b)
{
	ft_printf("ss\n");
	swap_a_or_b(stack_a);
	swap_a_or_b(stack_b);
}

void	addfront_stack(t_node **stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		free_stack(stack);
		return ;
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

void	push_on_top(t_node **stack_push, t_node **stack_pull)
{
	t_node	*temp;

	if (!stack_pull || !*stack_pull)
		return ;
	ft_printf("pa or pb\n");
	temp = (*stack_pull);
	addfront_stack(stack_push, temp->value);
	if ((*stack_pull)->next)
	{
		(*stack_pull) = (*stack_pull)->next;
		(*stack_pull)->prev = NULL;
	}
	else
		*stack_pull = NULL;
	free(temp);
}
