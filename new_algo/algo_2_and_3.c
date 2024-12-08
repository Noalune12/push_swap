/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2_and_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:01:17 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/08 11:01:18 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **stack)
{
	t_node	*temp;

	temp = (*stack)->next;
	if ((*stack)->value > temp->value)
		swap_a_or_b(stack, 'a', 0);
}

void	sort_3(t_node **stack_a)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = (*stack_a)->value;
	nb2 = (*stack_a)->next->value;
	nb3 = (*stack_a)->prev->value;
	if (is_sorted(*stack_a) == 1)
		return ;
	else if (nb1 < nb2 && nb1 < nb3 && nb2 > nb3)
	{
		swap_a_or_b(stack_a, 'a', 0);
		rotate_a_or_b(stack_a, 'a', 0);
	}
	else if (nb1 > nb2 && nb1 < nb3 && nb2 < nb3)
		swap_a_or_b(stack_a, 'a', 0);
	else if (nb1 < nb2 && nb1 > nb3 && nb2 > nb3)
		reverse_a_or_b(stack_a, 'a', 0);
	else if (nb1 > nb2 && nb1 > nb3 && nb2 < nb3)
		rotate_a_or_b(stack_a, 'a', 0);
	else if (nb1 > nb2 && nb1 > nb3 && nb2 > nb3)
	{
		swap_a_or_b(stack_a, 'a', 0);
		reverse_a_or_b(stack_a, 'a', 0);
	}
}
