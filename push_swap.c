/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:07 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/02 16:34:13 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	while (temp)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	*stack = NULL;
}

void	push_stack(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		free_stack(stack);
		return ;
	}
	new_node->value = value;
	new_node->next = NULL;
	if (*stack)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
	else
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*temp;
	size_t	i;

	stack_a = NULL;
	if (argc < 2) // Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre l’invite de commande.
	{
		ft_printf("Error\n");
		return (1);
	}
	// check error -> if not a number, not included in int, or double ?? string with numbers separated with space ??
	if (check_args(argc, argv) != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	i = 0;
	while (++i < argc)
		push_stack(&stack_a, ft_atoi(argv[i]));
	while (stack_a->next)
	{
		printf("stack a = %d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("stack a = %d\n", stack_a->value);
	while (stack_a->prev)
	{
		printf("stack a prev = %d\n", stack_a->value);
		stack_a = stack_a->prev;
	}
	printf("stack a prev = %d\n", stack_a->value);
	free_stack(&stack_a);
	return (0);
}
