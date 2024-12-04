#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	t_node	*current;
	t_node	*prev;

	if (!stack || !(stack->next))
		return (1);
	current = stack->next;
	prev = stack;
	while (current)
	{
		if (prev->value > current->value)
			return (-1);
		current = current->next;
		prev = prev->next;
	}
	return (1);
}

void	sort_3(t_node **stack_a)
{
	if (is_sorted(*stack_a) == 1)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a_or_b(stack_a, 'a', 0);
	if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		reverse_a_or_b(stack_a, 'a', 0);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a_or_b(stack_a, 'a', 0);
}
