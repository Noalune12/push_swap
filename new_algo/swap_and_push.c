/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:43:02 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/06 15:18:32 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_printf/ft_printf.h"

void	swap_a_or_b(t_node **stack, char c, int ss)
{
	int		top_value;
	t_node	*node2;

	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	if (c == 'a' && ss == 0)
		ft_printf("sa\n");
	else if (c == 'b' && ss == 0)
		ft_printf("sb\n");
	top_value = (*stack)->value;
	node2 = (*stack)->next;
	(*stack)->value = node2->value;
	node2->value = top_value;
}

void	swap_a_and_b(t_node **stack_a, t_node **stack_b)
{
	ft_printf("ss\n");
	swap_a_or_b(stack_a, 'a', 1);
	swap_a_or_b(stack_b, 'b', 1);
}

// static void	addfront_stack(t_node **stack, int value)
// {
// 	t_node	*new_node;

// 	new_node = (t_node *)malloc(sizeof(t_node));
// 	if (!new_node)
// 	{
// 		free_stack(stack);
// 		return ;
// 	}
// 	new_node->value = value;
// 	new_node->next = NULL;
// 	new_node->prev = NULL;
// 	if (*stack)
// 	{
// 		new_node->next = *stack;
// 		(*stack)->prev = new_node;
// 	}
// 	*stack = new_node;
// }

void	update_index(t_node **stack)
{
	t_node	*temp;

	if (!stack || !(*stack))
		return ;
	temp = (*stack);
	temp->index = 0;
	if (temp->next != temp)
		temp = temp->next;
	while (temp != *stack)
	{
		temp->index = temp->prev->index + 1;
		temp = temp->next;
	}
}

void	push_on_top(t_node **stack_push, t_node **stack_pull, char c)
{
	t_node	*top_pull;
	t_node	*last_push;

	if (!stack_pull || !*stack_pull)
		return ;
	top_pull = *stack_pull;
	if (top_pull->next == top_pull)
		*stack_pull = NULL;
	else
	{
		top_pull->prev->next = top_pull->next;
		top_pull->next->prev = top_pull->prev;
		*stack_pull = top_pull->next;
		update_index(stack_pull);
	}
	if (!*stack_push || !stack_push)
	{
		top_pull->next = top_pull;
		top_pull->prev = top_pull;
		top_pull->index = 0;
		*stack_push = top_pull;
	}
	else
	{
		last_push = (*stack_push)->prev;
		top_pull->next = *stack_push;
		top_pull->prev = last_push;
		last_push->next = top_pull;
		(*stack_push)->prev = top_pull;
		(*stack_push) = top_pull;
		update_index(stack_push);
	}
}
