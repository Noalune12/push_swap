/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:34:54 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/09 11:00:02 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_cheapest_element(int *costs, int size)
{
	int	min_cost;
	int	min_index;
	int	i;

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

static void	push_back(t_node **stack_a, t_node **stack_b, int value)
{
	int	target_pos;
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

static void	check_sorted(t_node **stack_a)
{
	int	target_pos;
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

static int	sort_a_to_b(t_node **stack_a, t_node **stack_b)
{
	int		*costs;
	int		*r_or_rr;
	int		cheapest_index;

	costs = (int *)malloc(get_stack_size(*stack_a) * sizeof(int));
	if (!costs)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (-1);
	}
	r_or_rr = (int *)malloc(get_stack_size(*stack_a) * sizeof(int));
	if (!r_or_rr)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (-1);
	}
	calculate_cost(*stack_a, *stack_b, costs, r_or_rr);
	cheapest_index = find_cheapest_element(costs, get_stack_size(*stack_a));
	rotate_or_reverse(stack_a, stack_b, cheapest_index,
		r_or_rr[cheapest_index]);
	free(costs);
	free(r_or_rr);
	return (0);
}

int	sort_500(t_node **stack_a, t_node **stack_b)
{
	int	ret;

	if (is_sorted(*stack_a) == 1)
		return (0);
	push_on_top(stack_b, stack_a, 'b');
	if (get_stack_size(*stack_a) > 4)
		push_on_top(stack_b, stack_a, 'b');
	while (get_stack_size(*stack_a) > 3 && is_sorted(*stack_a) == -1)
	{
		ret = sort_a_to_b(stack_a, stack_b);
		if (ret == -1)
			return (-1);
	}
	if (get_stack_size(*stack_a) == 3)
		sort_3(stack_a);
	while (*stack_b)
		push_back(stack_a, stack_b, (*stack_b)->value);
	check_sorted(stack_a);
	return (0);
}
