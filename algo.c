// quick sort
// element pivot (dernier element) -> a droite plus grand, a gauche plus petit
// recursive

#include "push_swap.h"
#include "libft/ft_printf/ft_printf.h"

int	is_sorted_reverse(t_node *stack)
{
	t_node	*current;
	t_node	*prev;

	if (!stack || !(stack->next))
		return (1);
	current = stack->next;
	prev = stack;
	while (current)
	{
		// ft_printf("is_sorted = %d vs %d\n", prev->value, current->value);
		if (prev->value < current->value)
			return (-1);
		current = current->next;
		prev = prev->next;
	}
	return (1);
}

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
		// ft_printf("is_sorted = %d vs %d\n", prev->value, current->value);
		if (prev->value > current->value)
			return (-1);
		current = current->next;
		prev = prev->next;
	}
	return (1);
}

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

void	quick_sort(t_node **stack_a, t_node **stack_b)
{
	while (is_sorted_reverse(*stack_a) != 1 || is_sorted_reverse(*stack_b) != 1)
	{
		partition(stack_a, stack_b, (*stack_a)->value, get_stack_size(*stack_a));
		ft_printf("\n\npartition a\n\n");
		print_stack(*stack_a, 'a');
		ft_printf("\n\n");
		print_stack(*stack_b, 'b');
		partition(stack_b, stack_a, (*stack_b)->value, get_stack_size(*stack_b));
		ft_printf("\n\npartition b\n\n");
		print_stack(*stack_a, 'a');
		ft_printf("\n\n");
		print_stack(*stack_b, 'b');
	}
	while (is_sorted(*stack_a) != 1)
		reverse_a_or_b(stack_a);
	//while (is_sorted(*stack_b) != 1)
		reverse_a_or_b(stack_b);
		ft_printf("\n\n");
	print_stack(*stack_b, 'b');
		reverse_a_or_b(stack_b);
		ft_printf("\n\n");
	print_stack(*stack_b, 'b');
		reverse_a_or_b(stack_b);
ft_printf("\n\n");
	print_stack(*stack_b, 'b');
	ft_printf("\n\nsort\n\n");
	print_stack(*stack_a, 'a');
	ft_printf("\n\n");
	print_stack(*stack_b, 'b');
}
