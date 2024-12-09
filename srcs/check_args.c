/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:01:55 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/09 14:06:50 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

static int	free_stack_error(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	if (!stack || !*stack)
		return (-1);
	temp = *stack;
	while (temp)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	*stack = NULL;
	return (-1);
}

static int	check_double(t_node *stack_a, int nb)
{
	t_node	*temp;

	temp = stack_a;
	while (temp)
	{
		if (temp->value == nb)
			return (1);
		temp = temp->next;
	}
	return (-1);
}

static int	handle_conversion(char *str, size_t *index, long *res, int sign)
{
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		if (*res > (LONG_MAX - (str[*index] - '0')) / 10)
			return (-1);
		*res = *res * 10 + (str[*index] - '0');
		if (*res * sign < INT_MIN || *res * sign > INT_MAX)
			return (-1);
		(*index)++;
	}
	return (0);
}

static int	validate_and_convert(char *str, size_t *index, t_node **stack_a)
{
	long	res;
	int		sign;
	int		ret;

	res = 0;
	sign = 1;
	if (str[*index] == '-' || str[*index] == '+')
	{
		if (str[*index] == '-')
			sign = -1;
		(*index)++;
	}
	if (!(str[*index] >= '0' && str[*index] <= '9'))
		return (-1);
	if (handle_conversion(str, index, &res, sign) == -1)
		return (-1);
	res *= sign;
	if (check_double(*stack_a, res) == 1)
		return (-1);
	ret = push_stack(stack_a, res);
	if (ret == -1)
		return (-1);
	return (1);
}

int	check_error(int ac, char **av, t_node **stack_a)
{
	int		i;
	size_t	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (!av[i][j])
			return (free_stack_error(stack_a));
		while (av[i][j])
		{
			while (av[i][j] == ' ')
				j++;
			if (av[i][j] && validate_and_convert(av[i], &j, stack_a) != 1)
				return (free_stack_error(stack_a));
			if (av[i][j] && av[i][j] != ' ')
				return (free_stack_error(stack_a));
		}
	}
	return (1);
}
