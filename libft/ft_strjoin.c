/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 00:56:23 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/26 01:33:01 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*ft_strcat(char	*dest, char	*src)
{
	int	i;
	int	destlen;

	i = 0;
	destlen = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (dest);
}

static char	*ft_strcpy(char	*dest, char	*src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		total;
	char		*str;
	char		*c1;
	char		*c2;

	if (!s1 || !s2)
		return (0);
	c1 = (char *)s1;
	c2 = (char *)s2;
	total = ft_strlen(c1) + ft_strlen(c2);
	str = (char *)malloc((total + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	ft_strcpy(str, c1);
	ft_strcat(str, c2);
	free(c1);
	return (str);
}
