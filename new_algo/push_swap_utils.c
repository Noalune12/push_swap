/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:38:45 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/08 11:44:42 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_value(t_node *stack, int index)
{
	t_node	*current;
	int		value;

	if (!stack)
		return (-1);
	current = stack;
	while (current->index != index)
		current = current->next;
	value = current->value;
	return (value);
}

int	is_sorted(t_node *stack)
{
	t_node	*current;

	if (!stack || stack->next == stack)
		return (1);
	current = stack;
	while (current->next != stack)
	{
		if (current->value > current->next->value)
			return (-1);
		current = current->next;
	}
	return (1);
}

int	get_stack_size(t_node *stack)
{
	int		size;
	t_node	*current;

	if (!stack)
		return (0);
	size = 1;
	current = stack;
	while (current->next != stack)
	{
		size++;
		current = current->next;
	}
	return (size);
}
