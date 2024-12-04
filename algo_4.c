// #include "push_swap.h"

// int	is_sorted_reverse(t_node *stack)
// {
// 	t_node	*current;
// 	t_node	*prev;

// 	if (!stack || !(stack->next))
// 		return (1);
// 	current = stack->next;
// 	prev = stack;
// 	while (current)
// 	{
// 		// ft_printf("is_sorted = %d vs %d\n", prev->value, current->value);
// 		if (prev->value < current->value)
// 			return (-1);
// 		current = current->next;
// 		prev = prev->next;
// 	}
// 	return (1);
// }

// void	partition_lower(t_node **stack_a, t_node **stack_b, int pivot, int size)
// {
// 	while (size > 1) {
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

// void	sort_4(t_node **stack_a, t_node **stack_b)
// {
// 	while (is_sorted(*stack_a) != 1 || is_sorted_reverse(*stack_b) != 1)
// 	{
// 		if (*stack_a)
// 			partition_lower(stack_a, stack_b, (*stack_a)->value, get_stack_size(*stack_a));
// 		if (*stack_b)
// 			partition_greater(stack_b, stack_a, (*stack_b)->value, get_stack_size(*stack_b));
// 	}
// 	if ((*stack_a)->value < (*stack_b)->value)
// 		push_on_top(stack_b, stack_a);
// 	while (is_sorted(*stack_a) != 1 || is_sorted_reverse(*stack_b) != 1)
// 	{
// 		if (*stack_a)
// 			partition_lower(stack_a, stack_b, (*stack_a)->value, get_stack_size(*stack_a));
// 		if (*stack_b)
// 			partition_greater(stack_b, stack_a, (*stack_b)->value, get_stack_size(*stack_b));
// 	}
// 	while (is_sorted(*stack_a) != 1 || *stack_b)
// 		push_on_top(stack_a, stack_b);
// }
