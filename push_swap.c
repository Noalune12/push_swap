/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:07 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/09 10:24:19 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	if (!stack || !*stack)
		return (-1);
	if ((*stack)->next->index == 0)
	{
		free(*stack);
		return (-1);
	}
	temp = (*stack)->next;
	while (temp->index != 0)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	free(temp);
	*stack = NULL;
	return (-1);
}

int	push_stack(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (free_stack(stack));
	new_node->value = value;
	new_node->next = NULL;
	if (*stack)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
		new_node->index = new_node->prev->index + 1;
	}
	else
	{
		*stack = new_node;
		new_node->index = 0;
		new_node->prev = NULL;
	}
	return (0);
}

void	update_prev_next(t_node **stack)
{
	t_node	*temp;

	temp = *stack;
	if (temp->next == NULL)
	{
		temp->next = temp;
		temp->prev = temp;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
}

static int	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int		ret;

	if (get_stack_size(*stack_a) == 2)
		sort_2(stack_a);
	else if (get_stack_size(*stack_a) == 3)
		sort_3(stack_a);
	else if (get_stack_size(*stack_a) > 3)
	{
		ret = sort_500(stack_a, stack_b);
		if (ret == -1)
		{
			free_stack(stack_a);
			free_stack(stack_b);
			return (-1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		ret;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (check_error(argc, argv, &stack_a) != 1)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	update_prev_next(&stack_a);
	ret = sort_stack(&stack_a, &stack_b);
	if (ret == -1)
		return (1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
