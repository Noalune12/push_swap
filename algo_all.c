// #include "push_swap.h"
// #include <stdio.h>

// void	partition_lower(t_node **stack_a, t_node **stack_b, int pivot, int size)
// {
// 	while (size > 0) {
// 		// printf("pivot = %d & stack_a = %d\n\n", pivot, (*stack_a)->value);
// 		if ((*stack_a)->value < pivot)
// 			push_on_top(stack_b, stack_a);
// 		else
// 			rotate_a_or_b(stack_a);
// 		size--;
// 	}
// }

// void	partition_greater(t_node **stack_a, t_node **stack_b, int pivot, int size)
// {
// 	while (size > 0)
// 	{
// 		// printf("pivot = %d & stack_a = %d\n\n", pivot, (*stack_a)->value);
// 		if ((*stack_a)->value > pivot)
// 			push_on_top(stack_b, stack_a);
// 		else
// 			rotate_a_or_b(stack_a);
// 		size--;
// 	}
// }

// void	quick_sort_a(t_node **stack_a, t_node **stack_b)
// {
// 	int	size;
// 	int	pivot;
// 	t_node	*temp;

// 	size = get_stack_size(*stack_a) / 2;
// 	if (get_stack_size(*stack_a) % 2 != 0)
// 		size++;
// 	printf("size / 2 = %d\n\n", size);
// 	temp = (*stack_a);
// 	while (--size > 0)
// 		temp = temp->next;
// 	pivot = temp->value;
// 	printf("pivot = %d\n\n", pivot);
// 	partition_lower(stack_a, stack_b, pivot, get_stack_size(*stack_a));
// }

// void	quick_sort_b(t_node **stack_a, t_node **stack_b)
// {
// 	int	size;
// 	int	pivot;
// 	t_node	*temp;

// 	size = get_stack_size(*stack_a) / 2;
// 	if (get_stack_size(*stack_a) % 2 != 0)
// 		size++;
// 	printf("size / 2 = %d\n\n", size);
// 	temp = (*stack_a);
// 	while (--size > 0)
// 		temp = temp->next;
// 	pivot = temp->value;
// 	printf("pivot = %d\n\n", pivot);
// 	partition_greater(stack_b, stack_a, pivot, get_stack_size(*stack_b));
// }

// void	quick_sort(t_node **stack_a, t_node **stack_b)
// {
// 	if (*stack_a)
// 		quick_sort_a(stack_a, stack_b);
// 	if (*stack_b)
// 		quick_sort_b(stack_b, stack_a);
// }


// void	sort_all(t_node **stack_a, t_node **stack_b)
// {
// 	int i = 0;
// 	while (i < 10)
// 	{
// 		quick_sort(stack_a, stack_b);
// 		i++;
// 	}
// }
