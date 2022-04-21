/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:43:49 by hbouhsis          #+#    #+#             */
/*   Updated: 2021/11/16 21:53:28 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if (!(size) || !(count))
	{
		str = (void *)malloc(size);
		str[0] = '\0';
		return (str);
	}
	str = (void *)malloc(size * count);
	if (!str)
		return (0);
	ft_bzero(str, size * count);
	return (str);
}
