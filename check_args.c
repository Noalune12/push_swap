#include "push_swap.h"
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

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

static int	check_int(char *str, t_node **stack_a) //accept all whitespace ??
{
	int				sign;
	long			res;
	size_t			i;

	i = 0;
	while (str[i])
	{
		sign = 1;
		res = 0;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -sign;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
		if (str[i] != ' ' && str[i])
			return (-1);
		res = res * sign;
		if (res < INT_MIN || res > INT_MAX || check_double(*stack_a, res) == -1)
			return (-1);
		push_stack(stack_a, res);
		if (!str[i])
			return (1);
		i++;
	}
	return (1);
}

static int	check_error(int ac, char **av, t_node **stack_a)
{
	size_t	i;

	i = 0;
	while (++i < ac)
	{
		if (check_int(av[i], stack_a) != 1)
			return (-1);
	}
	return (1);
}

int	check_args(int ac, char **av, t_node **stack_a)
{
	if (check_error(ac, av, stack_a) != 1)
	{
		free_stack(stack_a);
		return (-1);
	}
	return (1);
}
