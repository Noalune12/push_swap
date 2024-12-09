/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:02:08 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/09 11:00:27 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_position_a(t_node *stack, int value)
{
	t_node	*current;
	int		position;
	int		size;

	if (value < get_min(stack) || value > get_max(stack))
		return (find_min_index(stack));
	current = stack;
	position = 0;
	size = get_stack_size(stack);
	while (position < size)
	{
		if (current->value > value && current->prev->value < value)
			return (position);
		position++;
		current = current->next;
	}
	return (0);
}

int	find_position_b(t_node *stack, int value)
{
	t_node	*current;
	int		position;
	int		size;

	if (value < get_min(stack) || value > get_max(stack))
		return (find_max_index(stack));
	current = stack;
	position = 0;
	size = get_stack_size(stack);
	while (position < size)
	{
		if (current->value < value && current->prev->value > value)
			return (position);
		position++;
		current = current->next;
	}
	return (0);
}
