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
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = (*stack_a)->value;
	nb2 = (*stack_a)->next->value;
	nb3 = (*stack_a)->next->next->value;
	if (is_sorted(*stack_a) == 1)
		return ;
	else if (nb1 < nb2 && nb1 < nb3 && nb2 > nb3)
	{
		swap_a_or_b(stack_a, 'a', 0);
		rotate_a_or_b(stack_a, 'a', 0);
	}
	else if (nb1 > nb2 && nb1 < nb3 && nb2 < nb3)
		swap_a_or_b(stack_a, 'a', 0);
	else if (nb1 < nb2 && nb1 > nb3 && nb2 > nb3)
		reverse_a_or_b(stack_a, 'a', 0);
	else if (nb1 > nb2 && nb1 > nb3 && nb2 < nb3)
		rotate_a_or_b(stack_a, 'a', 0);
	else if (nb1 > nb2 && nb1 > nb3 && nb2 > nb3)
	{
		swap_a_or_b(stack_a, 'a', 0);
		reverse_a_or_b(stack_a, 'a', 0);
	}
}
