#include "push_swap.h"
#include <stdio.h> //remove

int	get_key_number_index(t_node *stack_s, int call) //check entier vs virgule ??
{
	int	key_number_index;

	key_number_index = get_stack_size(stack_s) / 4;
	if (call == 1)
	{
		if ((get_stack_size(stack_s) % 4) != 0)
		 	key_number_index++;
	}
	else if (call == 2)
	{
		if ((get_stack_size(stack_s) % 4) != 0)
		 	key_number_index++;
		key_number_index *= 2;
	}
	else if (call == 3)
	{
		if ((get_stack_size(stack_s) % 4) != 0)
		 	key_number_index++;
		key_number_index *= 3;
	}	// else if (call == 4)
	// 	key_number_index = get_stack_size(stack_s) / 8 * 4;
	// else if (call == 6)
	// 	key_number_index = get_stack_size(stack_s) / 8 * 5;
	// else if (call == 7)
	// 	key_number_index = get_stack_size(stack_s) / 8 * 6;
	// else if (call == 8)
	// 	key_number_index = get_stack_size(stack_s) / 8 * 7;
	return (key_number_index);
}

int	get_key_index(t_node *stack_s, int call) //save in a tab the key_number ??
{
	int	key_number_index;
	int	key_number;
	t_node	*temp;

	key_number_index = get_key_number_index(stack_s, call);
	// printf("index == %d\n\n", key_number_index);
	temp = stack_s;
	while (--key_number_index)
		temp = temp->next;
	key_number = temp->value;
	// printf("number == %d\n\n", key_number);
	return (key_number);
}

void	get_last_node(t_node **stack)
{
	t_node	*temp;

	if (!*stack || !stack)
		return ;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	*stack = temp;
}

int	find_under_key_number(t_node *stack_a, int key_number)
{
	t_node	*temp;

	temp = stack_a;
	while (temp)
	{
		if (temp->value < key_number)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static int	get_index(t_node *stack_a, int value)
{
	t_node	*temp;
	int		index;

	temp = stack_a;
	index = 0;
	while (temp)
	{
		if (temp->value == value)
			return (index);
		index++;
		temp = temp->next;
	}
	return (-1);
}

static void	push_number_up(t_node **stack_a, int value)
{
	int	index;
	int	proximity;

	index = get_index(*stack_a, value);
	proximity = get_stack_size(*stack_a) / 2;
	if (proximity > index)
		rotate_a_or_b(stack_a, 'a', 0);
	else
		reverse_a_or_b(stack_a, 'a', 0);
}

void	sort_100(t_node **stack_a, t_node **stack_b, t_node *stack_s, int key_number)
{
	t_node	*temp;
	t_node	*temp2;
	size_t	index_next;
	size_t	index_prev;

	while (find_under_key_number(*stack_a, key_number) == 1)
	{
		temp = *stack_a;
		temp2 = *stack_a;
		get_last_node(&temp2);
		index_next = 0;
		index_prev = 0;

		print_stack(stack_s, 's');
		printf("\n\n");
		while (temp->value >= key_number && temp->next)
		{
			temp = temp->next;
			index_next++;
		}
		while (temp2->value >= key_number && temp2->prev)
		{
			temp2 = temp2->prev;
			index_prev++;
		}
		printf("index next = %zu vs index prev = %zu\n\n", index_next, index_prev);
		if (index_next <= index_prev)
		{
			while ((*stack_a)->value != temp->value)
				push_number_up(stack_a, temp->value);
			printf("index next\n\n");

		}
		else
		{
			while ((*stack_a)->value != temp2->value)
				push_number_up(stack_a, temp2->value);
			printf("index prev\n\n");
		}
		push_on_top(stack_b, stack_a, 'b');
	}
	//sort_10(stack_a, stack_b, 100);
}
