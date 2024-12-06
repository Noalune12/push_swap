#include "push_swap.h"
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

static void	free_stack(t_node **stack)
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

static int	check_double(t_node *stack_a, int nb)
{
	t_node	*temp;

	temp = stack_a;
	while (temp)
	{
		if (temp->value == nb)
			return (-1);
		temp = temp->next;
	}
	return (1);
}

static int	validate_and_convert(char *str, size_t *index, t_node **stack_a)
{
	long	res;
	int		sign;

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
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		res = res * 10 + (str[*index] - '0');
		if (res * sign < INT_MIN || res * sign > INT_MAX)
			return (-1);
		(*index)++;
	}
	res *= sign;
	if (check_double(*stack_a, res) == -1)
		return (-1);
	push_stack(stack_a, res);
	return (1);
}

static int	check_int(char *str, t_node **stack_a)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] && validate_and_convert(str, &i, stack_a) != 1)
			return (-1);
		if (str[i] && str[i] != ' ')
			return (-1);
	}
	return (1);
}

int	check_error(int ac, char **av, t_node **stack_a)
{
	size_t	i;

	i = 0;
	while (++i < ac)
	{
		if (check_int(av[i], stack_a) != 1)
		{
			free_stack(stack_a);
			return (-1);
		}
	}
	return (1);
}

// int	check_args(int ac, char **av, t_node **stack_a)
// {
// 	if (check_error(ac, av, stack_a) != 1)
// 	{
// 		free_stack(stack_a);
// 		return (-1);
// 	}
// 	return (1);
// }
