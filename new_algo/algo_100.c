#include "push_swap.h"

int	cost_to_top_a(t_node *stack, int index)
{
	int	size;

	size = get_stack_size(stack);

	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

int	cost_to_top_b(t_node *stack, int index)
{
	int	size;

	size = get_stack_size(stack) + 1;

	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

// trouver la position cible dans b
// current-> value > value && current->prev->value > value
int	find_position_b(t_node *stack, int value)
{
	t_node	*current;
	int		position;
	int		size;
	int		min;
	int		max;

	min = get_min(stack);
	max = get_max(stack);
	if (value < min)
		return (find_max_index(stack));
	if (value > max)
		return (find_max_index(stack));
	current = stack;
	position = 0;
	size = get_stack_size(stack);
	if (!stack)
		return (0);
	while (position < size)
	{
		if (current->value < value && current->prev->value > value)
			return (position);
		position++;
		current = current->next;
	}
	return (0);
}

int	get_rr_r(int a, int b)
{
	int	count;

	count = 0;
	while (a && b)
	{
		a--;
		b--;
		count++;
	}
	if (a)
		count += a;
	else if (b)
		count += b;
	return (count);
}

void	compare_cost(t_node *stack_a, t_node *stack_b, t_node *current, int *cost, int *r_or_rr)
{
	int	*costs_a;
	int	*costs_b;
	int	cost_r;
	int	cost_rr;
	int	target_pos;

	costs_a = (int *)malloc(2 * sizeof(int));
	costs_b = (int *)malloc(2 * sizeof(int));
	costs_a[0] = current->index;
	costs_a[1] = get_stack_size(stack_a) - current->index;
	target_pos = find_position_b(stack_b, current->value);
	if (target_pos == get_stack_size(stack_b))
	{
		costs_b[0] = 0;
		costs_b[1] = 0;
	}
	else
	{
		costs_b[0] = target_pos;
		costs_b[1] = get_stack_size(stack_b) - target_pos;
	}
	// printf("%d ====>  ra = %d, rra = %d, target pos = %d, rb = %d, rrb = %d\n\n", current->value, costs_a[0], costs_a[1], target_pos, costs_b[0], costs_b[1]);
	cost_r = get_rr_r(costs_a[0], costs_b[0]);
	cost_rr = get_rr_r(costs_a[1], costs_b[1]);
	// printf("%d ====>  cost_r = %d, cost_rr = %d\n\n", current->value, cost_r, cost_rr);
	// if (cost_r < 0)
	// 	cost_r -= cost_r;
	// if (cost_rr < 0)
	// 	cost_rr -= cost_rr;
	if (cost_r <= cost_rr) // what is best ir ra and rrb ????
	{
		*cost = cost_r;
		*r_or_rr = 1;
	}
	else
	{
		*cost = cost_rr;
		*r_or_rr = -1;
	}
	int cost_ra_rrb = costs_a[0] + costs_b[1];
	int cost_rra_rb = costs_a[1] + costs_b[0];
	if (*cost > cost_ra_rrb)
	{
		*cost = cost_ra_rrb;
		*r_or_rr = 2;
	}
	else if (*cost > cost_rra_rb)
	{
		*cost = cost_rra_rb;
		*r_or_rr = -2;
	}
	*cost += 1;
	free(costs_a);
	free(costs_b);
}

void	calculate_cost(t_node *stack_a, t_node *stack_b, int *costs, int *r_or_rr)
{
	t_node *current;
	int size_a;
	int i;

	current = stack_a;
	size_a = get_stack_size(stack_a);
	i = 0;
	while (i < size_a)
	{
		compare_cost(stack_a, stack_b, current, &costs[i], &r_or_rr[i]);
		current = current->next;
		i++;
	}
}

//cout total de chaque element
// amener a au sommet
// le push dans b

// trouver cheapest element

//depplacer

int find_cheapest_element(int *costs, int size)
{
	int min_cost;
	int min_index;
	int i;

	min_cost = costs[0];
	min_index = 0;
	i = 0;
	while (i < size)
	{
		if (costs[i] < min_cost)
		{
			min_cost = costs[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	get_value(t_node *stack, int index)
{
	t_node	*current;
	int		value;

	if (!stack)
		return (-1);
	current = stack;
	while (current->index != index)
		current = current->next;
	value = current->value;
	return (value);
}

void	rotate_or_reverse(t_node **stack_a, t_node **stack_b, int cheapest_index, int r_or_rr)
{
	int	ra;
	int	rb;
	int	target_pos;
	int	value;

	if (r_or_rr == 1) //reverse
	{
		ra = cheapest_index;
		value = get_value(*stack_a, cheapest_index);
		target_pos = find_position_b(*stack_b, value);
		if (target_pos == get_stack_size(*stack_b))
			rb = 0;
		else
			rb = target_pos;
		while (ra && rb)
		{
			rotate_a_and_b(stack_a, stack_b);
			ra--;
			rb--;
		}
		if (ra)
		{
			while (ra)
			{
				rotate_a_or_b(stack_a, 'a', 0);
				ra--;
			}
		}
		// printf("rb = %d, target pos = %d", rb, target_pos);
		if (rb)
		{
			while (rb)
			{
				rotate_a_or_b(stack_b, 'b', 0);
				rb--;
			}
		}
	}
	if (r_or_rr == -1) //rotate
	{
		ra = get_stack_size(*stack_a) - cheapest_index;
		value = get_value(*stack_a, cheapest_index);
		target_pos = find_position_b(*stack_b, value);
		if (target_pos == get_stack_size(*stack_b))
			rb = 0;
		else
			rb = get_stack_size(*stack_b) - target_pos;
		while (ra && rb)
		{
			reverse_a_and_b(stack_a, stack_b);
			ra--;
			rb--;
		}
		if (ra)
		{
			while (ra)
			{
				reverse_a_or_b(stack_a, 'a', 0);
				ra--;
			}
		}
		// printf("rb = %d, target pos = %d", rb, target_pos);
		if (rb)
		{
			while (rb)
			{
				reverse_a_or_b(stack_b, 'b', 0);
				rb--;
			}
		}
	}
	if (r_or_rr == 2) //ra and rrb
	{
		ra = cheapest_index;
		value = get_value(*stack_a, cheapest_index);
		target_pos = find_position_b(*stack_b, value);
		if (target_pos == get_stack_size(*stack_b))
			rb = 0;
		else
			rb = get_stack_size(*stack_b) - target_pos;
		while (ra)
		{
			rotate_a_or_b(stack_a, 'a', 0);
			ra--;
		}
		// printf("rb = %d, target pos = %d", rb, target_pos);
		while (rb)
		{
			reverse_a_or_b(stack_b, 'b', 0);
			rb--;
		}
	}
	if (r_or_rr == -2) //rra and rb
	{
		ra = get_stack_size(*stack_a) - cheapest_index;
		value = get_value(*stack_a, cheapest_index);
		target_pos = find_position_b(*stack_b, value);
		if (target_pos == get_stack_size(*stack_b))
			rb = 0;
		else
			rb = target_pos;
		while (ra)
		{
			reverse_a_or_b(stack_a, 'a', 0);
			ra--;
		}
		// printf("rb = %d, target pos = %d", rb, target_pos);
		while (rb)
		{
			rotate_a_or_b(stack_b, 'b', 0);
			rb--;
		}
	}
	push_on_top(stack_b, stack_a, 'b');
}

int	find_position_a(t_node *stack, int value)
{
	t_node	*current;
	int		position;
	int		size;
	int		min;
	int		max;

	min = get_min(stack);
	// printf("min = %d, index = %d\n\n", min, find_min_index(stack));
	max = get_max(stack);
	if (value < min)
		return (find_min_index(stack));
	if (value > max)
		return (find_min_index(stack));
	current = stack;
	position = 0;
	size = get_stack_size(stack);
	if (!stack)
		return (0);
	while (position < size)
	{
		if (current->value > value && current->prev->value < value)
		{
				if (position == get_stack_size(stack))
					return (0);
				else
					return (position);
		}
		position++;
		current = current->next;
	}
	return (0);
}

void	push_back(t_node **stack_a, t_node **stack_b, int value)
{
	int target_pos;
	int	size;

	size = get_stack_size(*stack_a);
	target_pos = find_position_a(*stack_a, value);
	if (target_pos <= size / 2)
	{
		while (find_position_a(*stack_a, value) != 0)
			rotate_a_or_b(stack_a, 'a', 0);
	}
	else
	{
		while (find_position_a(*stack_a, value) != 0)
			reverse_a_or_b(stack_a, 'a', 0);
	}
	push_on_top(stack_a, stack_b, 'a');
}

void	check_sorted(t_node **stack_a)
{
	int target_pos;
	int	size;

	if (is_sorted(*stack_a) != 1)
	{
		size = get_stack_size(*stack_a);
		target_pos = find_min_index(*stack_a);
		if (target_pos <= size / 2)
		{
			while (find_min_index(*stack_a) != 0)
				rotate_a_or_b(stack_a, 'a', 0);
		}
		else
		{
			while (find_min_index(*stack_a) != 0)
				reverse_a_or_b(stack_a, 'a', 0);
		}
	}
}

void	print_stack(t_node *stack, char c);
#include <stdio.h>

void	sort_100(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_a;
	int		*costs;
	int		*r_or_rr;
	int		cheapest_index;

	//condition is sorted return
	push_on_top(stack_b, stack_a, 'b');
	if (get_stack_size(*stack_a) > 4)
		push_on_top(stack_b, stack_a, 'b');
	// printf("\n\npb x2\n\n");
	// print_stack(*stack_a, 'a');
	// printf("\n\n");
	// print_stack(*stack_b, 'b');
	// printf("\n\n");

	//check cost to top
	int	rrrrr = 0;
	while (get_stack_size(*stack_a) > 3)
	{
		temp_a = *stack_a;
		// printf("min index = %d and max_index = %d\n\n", find_min_index(*stack_b), find_max_index(*stack_b));
		costs = (int *)malloc(get_stack_size(*stack_a) * sizeof(int));
		r_or_rr = (int *)malloc(get_stack_size(*stack_a) * sizeof(int));
		calculate_cost(*stack_a, *stack_b, costs, r_or_rr);
		int i = 0;
		// while (i < get_stack_size(*stack_a))
		// {
		// 	printf("cost %d and %d\n", costs[i], r_or_rr[i]);
		// 	i++;
		// }
		cheapest_index = find_cheapest_element(costs, get_stack_size(*stack_a));
		// printf("cheapest index = %d\n\n", cheapest_index);
		rotate_or_reverse(stack_a, stack_b, cheapest_index, r_or_rr[cheapest_index]);
		// printf("\n\nstep 1\n\n");
		// print_stack(*stack_a, 'a');
		// printf("\n\n");
		// print_stack(*stack_b, 'b');
		// printf("\n\n");
		if (r_or_rr[0] == 2 || r_or_rr[0] == -2)
			rrrrr++;
		free(costs);
		free(r_or_rr);
	}

	sort_3(stack_a);
	// printf("\n\nsort3\n\n");
	// print_stack(*stack_a, 'a');
	// printf("\n\n");
	// print_stack(*stack_b, 'b');
	// printf("\n\n");
	while (*stack_b)
		push_back(stack_a, stack_b, (*stack_b)->value);
	// printf("\n\npush back\n\n");
	// print_stack(*stack_a, 'a');
	// printf("\n\n");
	// print_stack(*stack_b, 'b');
	// printf("\n\n");

	check_sorted(stack_a);
	// printf("case with 2 and -2 = %d", rrrrr);
	// printf("\n\nsorted\n\n");
	// print_stack(*stack_a, 'a');
	// printf("\n\n");
	// print_stack(*stack_b, 'b');
	// printf("\n\n");
	// push to b --> ra & rb then pb
	// while (temp_a->next != (*stack_a))
	// {
	// 	calculate_cost(*stack_a, *stack_b, costs);
	// 	temp_a = temp_a->next;
	// }
	// calculate_cost(*stack_a, *stack_b, costs);
}
