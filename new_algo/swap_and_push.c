/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:43:02 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/06 12:38:00 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_printf/ft_printf.h"

void	swap_a_or_b(t_node **stack, char c, int ss)
{
	int		temp;
	t_node	*temp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if (c == 'a' && ss == 0)
		ft_printf("sa\n");
	else if (c == 'b' && ss == 0)
		ft_printf("sb\n");
	temp = (*stack)->value;
	temp2 = (*stack)->next;
	(*stack)->value = temp2->value;
	temp2->value = temp;
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

	temp = (*stack);
	temp->index = 0;
	if (temp->next->index != 0)
		temp = temp->next;
	while (temp->index != 0)
	{
		temp->index = temp->prev->index + 1;
		temp = temp->next;
	}
}

void	push_on_top(t_node **stack_push, t_node **stack_pull, char c)
{
	t_node	*temp;
	t_node	*temp2;

	temp = NULL;
	if (!stack_pull || !*stack_pull)
		return ;
	if (c == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	if (!*stack_push)
	{
		*stack_push = *stack_pull;
		if ((*stack_pull)->next->index != 0)
			temp = (*stack_pull)->next;
		else
			(*stack_pull) = NULL;
		(*stack_push)->next = (*stack_push);
		(*stack_push)->prev = (*stack_push);
		(*stack_push)->index = 0;
		if (temp)
		{
			temp2 = temp;
			if (temp->next->index == 1)
			{
				temp->index = 0;
				temp->prev = temp;
				temp->next = temp;
			}
			else
			{
				temp = temp->next;
				while (temp->index != 1)
					temp = temp->next;
				printf("index = %d\n\n", temp->index);
				temp2->prev = temp;
				temp->next = temp2;
				(*stack_pull) = temp2;
				update_index(stack_pull);
			}
		}
	}
	// temp = (*stack_pull);
	// addfront_stack(stack_push, temp->value);
	// if ((*stack_pull)->next)
	// {
	// 	(*stack_pull) = (*stack_pull)->next;
	// 	(*stack_pull)->prev = NULL;
	// }
	// else
	// 	*stack_pull = NULL;
	// free(temp);
}
