// #include "push_swap.h"

// void	partition_sort(t_node **stack_a, t_node **stack_b, int pivot, int size)
// {
// 	while (size > 0)
// 	{
// 		if ((*stack_a) || (*stack_a)->value < pivot)
// 			push_on_top(stack_b, stack_a);
// 		else
// 		{
// 			if (*stack_a)
// 				rotate_a_or_b(stack_a);
// 		}
// 		size--;
// 	}
// }

// void	quick_sort(t_node **stack_a, t_node **stack_b, int low, int high)
// {
// 	int	pivot;

// 	if (low < high)
// 	{
// 		pivot = (*stack_a)->value;
// 		partition_sort(stack_a, stack_b, pivot, get_stack_size(*stack_a));
// 		quick_sort(stack_a, stack_b, low, pivot - 1);
// 		quick_sort(stack_b, stack_a, pivot + 1, high);
// 	}
// }
