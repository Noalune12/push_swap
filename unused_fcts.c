/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused_fcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:40:14 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/08 11:40:25 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
