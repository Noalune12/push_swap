/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused_fcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:40:14 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/09 10:13:52 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ARG=""; ./a.out $ARG | ./checker_linux $ARG
// ARG=""; ./a.out $ARG | wc -l
//delete
// #include "libft/ft_printf/ft_printf.h"

// void	print_stack(t_node *stack, char c)
// {
// 	t_node	*temp;

// 	temp = stack;
// 	if (!temp)
// 	{
// 		ft_printf("STACK %c NULL", c);
// 		return ;
// 	}
// 	ft_printf("stack %c = %d && index = %d // prev : %p, next : %p\n",
// 		c, temp->value, temp->index, temp->prev, temp->next);
// 	temp = temp->next;
// 	while (temp->index != 0)
// 	{
// 		ft_printf("stack %c = %d && index = %d // prev : %p, next : %p\n",
// 			c, temp->value, temp->index, temp->prev, temp->next);
// 		temp = temp->next;
// 	}
// }

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
