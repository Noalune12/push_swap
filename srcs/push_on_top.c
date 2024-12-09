/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_on_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:45:35 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/09 11:00:35 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/ft_printf/ft_printf.h"

static void	remove_from_stack_pull(t_node **stack_pull)
{
	t_node	*top_pull;

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
}

static void	add_to_stack_push(t_node **stack_push, t_node *top_pull)
{
	t_node	*last_push;

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

void	push_on_top(t_node **stack_push, t_node **stack_pull, char c)
{
	t_node	*top_pull;

	if (!stack_pull || !*stack_pull)
		return ;
	if (c == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	top_pull = *stack_pull;
	remove_from_stack_pull(stack_pull);
	add_to_stack_push(stack_push, top_pull);
}
