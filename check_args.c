/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:15 by lbuisson          #+#    #+#             */
/*   Updated: 2024/12/03 08:44:24 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft/libft.h"

//check int -> cast en long et compare avec INT_MAX et INT MIN
static int	check_int(const char *nptr, int *tab)
{
	int				sign;
	long			res;
	size_t			i;

	sign = 1;
	res = 0;
	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	res = res * sign;
	if (res < INT_MIN || res > INT_MAX)
		return (-1);
	(*tab) = res;
	return (1);
}

//check double avec tab de int
static int	check_double(int *tab, int nb, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		if (tab[i] == nb)
			return (-1);
		i++;
	}
	return (1);
}

int	check_error(int ac, char **av, int *tab)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			if (!(ft_isdigit(av[i][j])))
				return (-1);
			j++;
		}
		if (check_int(av[i], &tab[k]) != 1 || check_double(tab, tab[k], k) != 1)
			return (-1);
		k++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int		*tab;

	tab = (int *)malloc(ac * sizeof(int));
	if (!tab)
		return (0);
	if (check_error(ac, av, tab) != 1)
	{
		free(tab);
		return (-1);
	}
	free(tab);
	return (1);
}
