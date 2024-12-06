/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:07 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/06 15:29:47 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

static void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	if (!stack || !*stack)
		return ;
	if ((*stack)->next->index == 0)
	{
		free(*stack);
		return ;
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
		new_node->index = new_node->prev->index + 1;
	}
	else
	{
		*stack = new_node;
		new_node->index = 0;
		new_node->prev = NULL;
	}
}

void	update_prev_next(t_node **stack)
{
	t_node	*temp;

	temp = *stack;
	if (temp->next == NULL)
	{
		temp->next = temp;
		temp->prev =temp;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
}

void	print_stack(t_node *stack, char c)
{
	t_node	*temp;

	temp = stack;
	if (!temp)
	{
		ft_printf("STACK %c NULL", c);
		return ;
	}
	ft_printf("stack %c = %d && index = %d // prev : %p, next : %p\n", c, temp->value, temp->index, temp->prev, temp->next);
	temp = temp->next;
	while (temp->index != 0)
	{
		ft_printf("stack %c = %d && index = %d // prev : %p, next : %p\n", c, temp->value, temp->index, temp->prev, temp->next);
		temp = temp->next;
	}
}

int	get_stack_size(t_node *stack)
{
	int	size;
	t_node *current;

	if (!stack)
		return (0);
	size = 1;
	current = stack;
	while (current->next != stack)
	{
		size++;
		current = current->next;
	}
	return (size);
}


#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2) // Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre l’invite de commande.
		return (1);
	// check error -> if not a number, not included in int, or double ?? string with numbers separated with space ??
	if (check_error(argc, argv, &stack_a) != 1)
	{
		//ft_printf("Error\n");
		ft_putendl_fd("Error", 2);
		return (1);
	}
	update_prev_next(&stack_a);
	// print_stack(stack_a, 'a');
	// ft_printf("\n\nSIZE === %d\n\n", get_stack_size(stack_a));
	if (get_stack_size(stack_a) == 1)
	{
		// ft_printf("\n\nsorted\n\n");
		// print_stack(stack_a, 'a');
		return (0);
	}
	if (get_stack_size(stack_a) == 2)
	{
		sort_2(&stack_a);
		// ft_printf("\n\nsorted\n\n");
		// print_stack(stack_a, 'a');
	}
	if (get_stack_size(stack_a) == 3)
	{
		sort_3(&stack_a);
		// ft_printf("\n\nsorted\n\n");
		// print_stack(stack_a, 'a');
	}
	// if (get_stack_size(stack_a) >= 4)
	// {
	// 	sort_10(&stack_a, &stack_b, 10);
	// 	ft_printf("\n\nsorted\n\n");
	// 	print_stack(stack_a, 'a');
	// }
	// if (argc >= 5)
	// {
	// 	sort_4(&stack_a, &stack_b);
	// 	ft_printf("\n\nsorted\n\n");
	// 	print_stack(stack_a, 'a');
	// 	ft_printf("\n\n");
	// 	print_stack(stack_b, 'b');
	// }
	// if (argc >= 5)
	// {
	// 	sort_4(&stack_a, &stack_b);
	// 	ft_printf("\n\nsorted\n\n");
	// 	print_stack(stack_a, 'a');
	// 	ft_printf("\n\n");
	// 	print_stack(stack_b, 'b');
	// }
	// ft_printf("\n\nswap a\n\n");
	// swap_a_and_b(&stack_a, &stack_b);
	// print_stack(stack_a, 'a');
	// ft_printf("\n\npush b\n\n");
	// push_on_top(&stack_b, &stack_a);
	// print_stack(stack_a, 'a');
	// ft_printf("\n\n");
	// print_stack(stack_b, 'b');
	// ft_printf("\n\npush a\n\n");
	// push_on_top(&stack_a, &stack_b);
	// print_stack(stack_a, 'a');
	// ft_printf("\n\n");
	// print_stack(stack_b, 'b');
	// ft_printf("\n\nrotate a\n\n");
	// rotate_a_or_b(&stack_a);
	// print_stack(stack_a, 'a');
	// ft_printf("\n\nreverse a\n\n");
	// reverse_a_or_b(&stack_a);
	// print_stack(stack_a, 'a');
	// ft_printf("\n\npartition\n\n");
	// partition(&stack_a, &stack_b, stack_a->value, get_stack_size(stack_a));
	// print_stack(stack_a, 'a');
	// ft_printf("\n\n");
	// print_stack(stack_b, 'b');
	// ft_printf("\n\npartition\n\n");
	// partition(&stack_b, &stack_a, stack_b->value, get_stack_size(stack_b));
	// print_stack(stack_a, 'a');
	// ft_printf("\n\n");
	// print_stack(stack_b, 'b');
	// quick_sort(&stack_a, &stack_b);
	// quick_sort(&stack_a, &stack_b);
	// quick_sort(&stack_a, &stack_b);
	// quick_sort(&stack_a, &stack_b);
	// quick_sort(&stack_a, &stack_b);
	// printf("stack a = %d\n", stack_a->value);
	// while (stack_a->prev)
	// {
	// 	printf("stack a prev = %d\n", stack_a->value);
	// 	stack_a = stack_a->prev;
	// }
	// printf("stack a prev = %d\n", stack_a->value);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
