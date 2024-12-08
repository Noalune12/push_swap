/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:07 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/06 08:11:05 by lbuisson         ###   ########lyon.fr   */
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

void	print_stack(t_node *stack, char c)
{
	t_node	*temp;

	temp = stack;
	while (temp)
	{
		ft_printf("stack %c = %d // prev : %p, next : %p\n", c, temp->value, temp->prev, temp->next);
		temp = temp->next;
	}
}

int	get_stack_size(t_node *stack)
{
	int	size;
	t_node *current;

	if (!stack)
		return (0);
	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}


#include <stdio.h>
void	sort_stack(t_node **stack_a, t_node **stack_s);
int get_key_index(t_node *stack_s, int call);
void	sort_100(t_node **stack_a, t_node **stack_b, t_node *stack_s, int key_number);

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*stack_s;
	size_t	i;
	int		key_number;

	stack_a = NULL;
	stack_b = NULL;
	stack_s = NULL;
	if (argc < 2) // Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre l’invite de commande.
		return (1);
	// check error -> if not a number, not included in int, or double ?? string with numbers separated with space ??
	if (check_error(argc, argv, &stack_a) != 1)
	{
		//ft_printf("Error\n");
		ft_putendl_fd("Error", 2);
		return (1);
	}
	i = 0;
	// while (++i < argc)
	// 	push_stack(&stack_a, ft_atoi(argv[i]));
	// print_stack(stack_a, 'a');
	// printf("\n\n");
	// sort_stack(&stack_a, &stack_s);
	// while (++i < 4)
	// {
	// 	key_number = get_key_index(stack_s, i);
	// 	sort_100(&stack_a, &stack_b, stack_s, key_number);
	// 	// printf("\n\n");
	// 	// print_stack(stack_a, 'a');
	// 	// printf("\n\n");
	// 	// print_stack(stack_b, 'b');
	// }
	// printf("\n\n");
	// print_stack(stack_s, 's');
	if (get_stack_size(stack_a) == 2)
	{
		sort_2(&stack_a);
		// ft_printf("\n\nsorted\n\n");
		// print_stack(stack_a, 'a');
	}
	if (get_stack_size(stack_a) == 3)
	{
		sort_3(&stack_a);
		ft_printf("\n\nsorted\n\n");
		print_stack(stack_a, 'a');
	}
	if (get_stack_size(stack_a) >= 4)
	{
		sort_10(&stack_a, &stack_b, 10);
		ft_printf("\n\nsorted\n\n");
		print_stack(stack_a, 'a');
	}
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
	free_stack(&stack_s);
	return (0);
}
