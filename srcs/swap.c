/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:43:02 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/09 11:00:55 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/ft_printf/ft_printf.h"

void	swap_a_or_b(t_node **stack, char c, int ss)
{
	int		top_value;
	t_node	*node2;

	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	if (c == 'a' && ss == 0)
		ft_printf("sa\n");
	else if (c == 'b' && ss == 0)
		ft_printf("sb\n");
	top_value = (*stack)->value;
	node2 = (*stack)->next;
	(*stack)->value = node2->value;
	node2->value = top_value;
}

void	swap_a_and_b(t_node **stack_a, t_node **stack_b)
{
	ft_printf("ss\n");
	swap_a_or_b(stack_a, 'a', 1);
	swap_a_or_b(stack_b, 'b', 1);
}
