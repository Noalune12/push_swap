#include "push_swap.h"

void	rotate_a_or_b(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	temp = (*stack);
	while (temp->next)
	{
		temp2 = temp->next;
		temp->next = temp2->next;
		temp->prev = temp;
		temp = temp2;
	}
	(*stack) = temp->next;
	while (temp2)
		temp2 = temp2->prev;
	(*stack)->next = temp2;
}
