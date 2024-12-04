#include "push_swap.h"

void	sort_2(t_node **stack)
{
	t_node	*temp;

	temp = (*stack)->next;
	if ((*stack)->value > temp->value)
		swap_a_or_b(stack, 'a', 0);
}
