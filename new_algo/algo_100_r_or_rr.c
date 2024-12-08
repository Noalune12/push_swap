/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100_r_or_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:13:32 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/08 10:57:51 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*use variable r_or_rr to do the best operations.
If -1 = rr, if 1 = rrr, if 2 = ra and rrb, if -2, rra and rb*/

static void	only_rotate(t_node **stack_a, t_node **stack_b,
	int cheapest_index, int value)
{
	int	ra;
	int	rb;

	ra = cheapest_index;
	if (find_position_b(*stack_b, value) == get_stack_size(*stack_b))
		rb = 0;
	else
		rb = find_position_b(*stack_b, value);
	while (ra && rb)
	{
		rotate_a_and_b(stack_a, stack_b);
		ra--;
		rb--;
	}
	while (ra)
	{
		rotate_a_or_b(stack_a, 'a', 0);
		ra--;
	}
	while (rb)
	{
		rotate_a_or_b(stack_b, 'b', 0);
		rb--;
	}
}

static void	only_reverse(t_node **stack_a, t_node **stack_b,
	int cheapest_index, int value)
{
	int	rra;
	int	rrb;

	rra = get_stack_size(*stack_a) - cheapest_index;
	if (find_position_b(*stack_b, value) == get_stack_size(*stack_b))
		rrb = 0;
	else
		rrb = get_stack_size(*stack_b) - find_position_b(*stack_b, value);
	while (rra && rrb)
	{
		reverse_a_and_b(stack_a, stack_b);
		rra--;
		rrb--;
	}
	while (rra)
	{
		reverse_a_or_b(stack_a, 'a', 0);
		rra--;
	}
	while (rrb)
	{
		reverse_a_or_b(stack_b, 'b', 0);
		rrb--;
	}
}

static void	rotate_a_reverse_b(t_node **stack_a, t_node **stack_b,
	int cheapest_index, int value)
{
	int	ra;
	int	rrb;

	ra = cheapest_index;
	if (find_position_b(*stack_b, value) == get_stack_size(*stack_b))
		rrb = 0;
	else
		rrb = get_stack_size(*stack_b) - find_position_b(*stack_b, value);
	while (ra)
	{
		rotate_a_or_b(stack_a, 'a', 0);
		ra--;
	}
	while (rrb)
	{
		reverse_a_or_b(stack_b, 'b', 0);
		rrb--;
	}
}

static void	reverse_a_rotate_b(t_node **stack_a, t_node **stack_b,
	int cheapest_index, int value)
{
	int	rra;
	int	rb;

	rra = get_stack_size(*stack_a) - cheapest_index;
	if (find_position_b(*stack_b, value) == get_stack_size(*stack_b))
		rb = 0;
	else
		rb = find_position_b(*stack_b, value);
	while (rra)
	{
		reverse_a_or_b(stack_a, 'a', 0);
		rra--;
	}
	while (rb)
	{
		rotate_a_or_b(stack_b, 'b', 0);
		rb--;
	}
}

void	rotate_or_reverse(t_node **stack_a, t_node **stack_b,
	int cheapest_index, int r_or_rr)
{
	int	value;

	value = get_value(*stack_a, cheapest_index);
	if (r_or_rr == 1)
		only_rotate(stack_a, stack_b, cheapest_index, value);
	if (r_or_rr == -1)
		only_reverse(stack_a, stack_b, cheapest_index, value);
	if (r_or_rr == 2)
		rotate_a_reverse_b(stack_a, stack_b, cheapest_index, value);
	if (r_or_rr == -2)
		reverse_a_rotate_b(stack_a, stack_b, cheapest_index, value);
	push_on_top(stack_b, stack_a, 'b');
}
