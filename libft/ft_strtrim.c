/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 01:13:44 by hbouhsis          #+#    #+#             */
/*   Updated: 2021/11/21 00:16:45 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	fnfirst(char const *s1, char const *set)
{
	int	i;
	int	first;

	i = 0;
	first = 0;
	while (set[i])
	{
		while (s1[first] == set[i])
		{
			first++;
			i = 0;
		}
		i++;
	}
	return (first);
}

static size_t	fnlast(char const *s1, char const *set)
{
	int		i;
	size_t	last;

	i = 0;
	last = ft_strlen(s1) - 1;
	while (set[i])
	{
		while (s1[last] == set[i])
		{
			last--;
			i = 0;
		}
		i++;
	}
	return (last);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	size_t	size;

	if (!(s1))
		return (NULL);
	first = fnfirst(s1, set);
	if (first >= ft_strlen(s1))
		return (ft_strdup("\0"));
	last = fnlast(s1, set);
	size = last - first + 1;
	return (ft_substr(s1, first, size));
}
