/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 07:52:58 by lbuisson          #+#    #+#             */
/*   Updated: 2024/11/13 08:23:10 by lbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countwords(char const *s, char c)
{
	size_t	count;
	size_t	i;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (!s[i + 1] && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_createstr(const char *s, char c, size_t *index)
{
	char	*str;
	size_t	i;
	size_t	index_temp;
	size_t	len;

	index_temp = *index;
	len = 0;
	while (s[index_temp] != c && s[index_temp])
	{
		index_temp++;
		len++;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[*index];
		(*index)++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_free(char **split)
{
	size_t	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			split[i] = NULL;
			i++;
		}
		free (split);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;
	size_t	index;
	size_t	j;

	count = countwords(s, c);
	split = (char **)malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	index = 0;
	j = 0;
	while (count > j)
	{
		while (s[index] == c)
			index++;
		split[j] = ft_createstr(s, c, &index);
		if (!split[j])
		{
			ft_free(split);
			return (NULL);
		}
		j++;
	}
	split[j] = NULL;
	return (split);
}
