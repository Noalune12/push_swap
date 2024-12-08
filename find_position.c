/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:02:08 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/08 11:02:09 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position_a(t_node *stack, int value)
{
	t_node	*current;
	int		position;

	if (value < get_min(stack))
		return (find_min_index(stack));
	if (value > get_max(stack))
		return (find_min_index(stack));
	current = stack;
	position = 0;
	if (!stack)
		return (0);
	while (position < get_stack_size(stack))
	{
		if (current->value > value && current->prev->value < value)
		{
			if (position == get_stack_size(stack))
				return (0);
			else
				return (position);
		}
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
	int		min;
	int		max;

	min = get_min(stack);
	max = get_max(stack);
	if (value < min)
		return (find_max_index(stack));
	if (value > max)
		return (find_max_index(stack));
	current = stack;
	position = 0;
	size = get_stack_size(stack);
	if (!stack)
		return (0);
	while (position < size)
	{
		if (current->value < value && current->prev->value > value)
			return (position);
		position++;
		current = current->next;
	}
	return (0);
}
