/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_and_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:02:16 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/09 08:33:52 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_node *stack)
{
	t_node	*current;
	int		min_value;
	int		min_index;

	current = stack;
	min_value = current->value;
	min_index = current->index;
	while (current->next != stack)
	{
		current = current->next;
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = current->index;
		}
	}
	if (current->value < min_value)
	{
		min_value = current->value;
		min_index = current->index;
	}
	return (min_index);
}

int	get_min(t_node *stack)
{
	t_node	*current;
	int		min_index;

	min_index = find_min_index(stack);
	current = stack;
	while (current->index != min_index)
		current = current->next;
	return (current->value);
}

int	find_max_index(t_node *stack)
{
	t_node	*current;
	int		max_value;
	int		max_index;

	current = stack;
	max_value = current->value;
	max_index = current->index;
	while (current->next != stack)
	{
		current = current->next;
		if (current->value > max_value)
		{
			max_value = current->value;
			max_index = current->index;
		}
	}
	if (current->value > max_value)
	{
		max_value = current->value;
		max_index = current->index;
	}
	return (max_index);
}

int	get_max(t_node *stack)
{
	t_node	*current;
	int		max_index;

	current = stack;
	max_index = find_max_index(stack);
	current = stack;
	while (current->index != max_index)
		current = current->next;
	return (current->value);
}
