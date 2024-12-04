#include "push_swap.h"


int	get_index_min(t_node *stack_a)
{
	t_node	*temp;
	int		index;
	int		min;
	int	min_index;

	temp = stack_a->next;
	min = stack_a->value;
	index = 0;
	min_index = index;
	while (temp)
	{
		index++;
		if (temp->value < min)
		{
			min = temp->value;
			min_index = index;
		}
		temp = temp->next;
	}
	return (min_index);
}

void	push_min_up(t_node **stack_a)
{
	int	index;
	int	proximity;

	index = get_index_min(*stack_a);
	proximity = get_stack_size(*stack_a) / 2;
	if (proximity > index)
		rotate_a_or_b(stack_a);
	else
		reverse_a_or_b(stack_a);
}

void	sort_10(t_node **stack_a, t_node **stack_b)
{
	int	index;

	while (get_stack_size(*stack_a) > 3 && is_sorted(*stack_a) == -1)
	{
		index = get_index_min(*stack_a);
		while (index != 0)
		{
			push_min_up(stack_a);
			index = get_index_min(*stack_a);
		}
		while (get_index_min(*stack_a) == 0)
		{
			push_on_top(stack_b, stack_a, 'b');
			if (get_stack_size(*stack_a) == 3)
				break ;
		}
    }
	sort_3(stack_a);
	while (*stack_b)
		push_on_top(stack_a, stack_b, 'a');
}
