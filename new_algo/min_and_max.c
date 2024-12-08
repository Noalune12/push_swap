#include "push_swap.h"

int find_min_index(t_node *stack)
{
	t_node	*current;
	int		min_value;
	int		min_index;

	if (!stack)
		return -1;
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

int get_min(t_node *stack)
{
	t_node	*current;
	int		min_value;
	int		min_index;

	if (!stack)
		return -1;
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
	return (min_value);
}

int find_max_index(t_node *stack)
{
	t_node	*current;
	int		max_value;
	int		max_index;

	if (!stack)
		return (-1);
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
	int		max_value;
	int		max_index;

	if (!stack)
		return (-1);
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
	return (max_value);
}
