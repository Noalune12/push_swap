#include "push_swap.h"

static int	is_in_s(int value, t_node *stack_s)
{
	t_node	*temp;

	temp = stack_s;
	while (temp)
	{
		if (temp->value == value)
			return (-1);
		temp = temp->next;
	}
	return (1);
}

static int	get_max(t_node *stack_a)
{
	t_node	*temp;
	int		max;

	temp = stack_a;
	max = stack_a->value;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

static int	get_min(t_node *stack_a, t_node *stack_s, int max)
{
	t_node	*temp;
	int		min;

	temp = stack_a;
	min = max;
	while (temp)
	{
		if (temp->value < min && is_in_s(temp->value, stack_s) == 1)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

static void	copy_stack(int	value, t_node **stack_s)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		//free_stack(stack); ???
		return ;
	}
	new_node->value = value;
	new_node->next = NULL;
	if (*stack_s)
	{
		temp = *stack_s;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
	else
	{
		*stack_s = new_node;
		new_node->prev = NULL;
	}
}

void	sort_stack(t_node **stack_a, t_node **stack_s)
{
	int	min;
	int	size;

	size = get_stack_size(*stack_a);
	while (get_stack_size(*stack_s) < size)
	{
		min = get_max(*stack_a);
		if (get_stack_size(*stack_s) == 0)
		{
			min = get_min(*stack_a, *stack_s, min);
			copy_stack(min, stack_s);
		}
		else
		{
			min = get_min(*stack_a, *stack_s, min);
			copy_stack(min, stack_s);
		}
	}
}
