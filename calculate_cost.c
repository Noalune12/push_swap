/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:06:40 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/08 10:55:53 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int	get_rr_r(int a, int b)
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

static void	compare_cost_mixed_r_rr(int costs_a_b[2][2],
	int *cost, int *r_or_rr)
{
	int	cost_ra_rrb;
	int	cost_rra_rb;

	cost_ra_rrb = costs_a_b[0][0] + costs_a_b[1][1];
	cost_rra_rb = costs_a_b[0][1] + costs_a_b[1][0];
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
}

static void	compare_cost(int costs_a_b[2][2], int *cost, int *r_or_rr)
{
	int	cost_r;
	int	cost_rr;

	cost_r = get_rr_r(costs_a_b[0][0], costs_a_b[1][0]);
	cost_rr = get_rr_r(costs_a_b[0][1], costs_a_b[1][1]);
	if (cost_r <= cost_rr)
	{
		*cost = cost_r;
		*r_or_rr = 1;
	}
	else
	{
		*cost = cost_rr;
		*r_or_rr = -1;
	}
	compare_cost_mixed_r_rr(costs_a_b, cost, r_or_rr);
	*cost += 1;
	ft_memset(costs_a_b[0], 0, sizeof(costs_a_b[0]));
	ft_memset(costs_a_b[1], 0, sizeof(costs_a_b[1]));
}

void	calculate_cost(t_node *stack_a, t_node *stack_b,
	int *costs, int *r_or_rr)
{
	t_node	*current;
	ssize_t	i;
	int		costs_a_b[2][2];
	int		target_pos;

	current = stack_a;
	i = -1;
	while (++i < get_stack_size(stack_a))
	{
		costs_a_b[0][0] = current->index;
		costs_a_b[0][1] = get_stack_size(stack_a) - current->index;
		target_pos = find_position_b(stack_b, current->value);
		if (target_pos == get_stack_size(stack_b))
		{
			costs_a_b[1][0] = 0;
			costs_a_b[1][1] = 0;
		}
		else
		{
			costs_a_b[1][0] = target_pos;
			costs_a_b[1][1] = get_stack_size(stack_b) - target_pos;
		}
		compare_cost(costs_a_b, &costs[i], &r_or_rr[i]);
		current = current->next;
	}
}
