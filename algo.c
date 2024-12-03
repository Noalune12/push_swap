// quick sort
// element pivot (dernier element) -> a droite plus grand, a gauche plus petit
// recursive

#include "push_swap.h"

// sort regarding pivot (first element of the list)
void	partition(t_node **stack_a, t_node **stack_b, int pivot, int size)
{
	while (size > 0) {
		printf("pivot = %d & stack_a = %d\n\n", pivot, (*stack_a)->value);
		if ((*stack_a)->value > pivot)
			push_on_top(stack_b, stack_a);
		else
			rotate_a_or_b(stack_a);
		size--;
	}
}

//do partition while stack_a and stack_b are not sorted
//when sorted find a wind to put back stack_b in stack_a
