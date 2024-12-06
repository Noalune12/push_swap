#include "push_swap.h"
// calculer le coût d'une rotation->
// renvoyer index si index >= size / 2 ==> ca veut dire qu'on rot en ra
// sinon size - index (rra)

int	cost_to_top(t_node *stack, int index)
{
	int	size;

	size = get_stack_size(stack);

	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

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

// trouver la position cible dans b
// current-> value > value && current->prev->value > value
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
		return (find_min_index(stack)) + 1;
	if (value > max)
		return (find_max_index(stack) + 1);
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

//cout total de chaque element
// amener a au sommet
// le push dans b

// trouver cheapest element

//depplacer

void	print_stack(t_node *stack, char c);
#include <stdio.h>

void	sort_100(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;

	//condition is sorted return
	push_on_top(stack_b, stack_a, 'b');
	push_on_top(stack_b, stack_a, 'b');
	printf("\n\npb x2\n\n");
	print_stack(*stack_a, 'a');
	printf("\n\n");
	print_stack(*stack_b, 'b');
	printf("\n\n");

	//check cost to top
	temp_a = *stack_a;
	temp_b = *stack_b;
	printf("min index = %d and max_index = %d\n\n", find_min_index(*stack_b), find_max_index(*stack_b));
	while (temp_a->next != (*stack_a))
	{
		int cost = cost_to_top(*stack_a, temp_a->index);
		int position = find_position_b(*stack_b, temp_a->value);
		printf("cost to top of %d ===== %d\nbest position in b = %d\n\n", temp_a->value, cost, position);
		temp_a = temp_a->next;
	}
	int cost = cost_to_top(*stack_a, temp_a->index);
	int position = find_position_b(*stack_b, temp_a->value);
	printf("cost to top of %d ===== %d\nbest position in b = %d\n", temp_a->value, cost, position);

}
