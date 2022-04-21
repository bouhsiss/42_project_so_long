/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:45:07 by hbouhsis          #+#    #+#             */
/*   Updated: 2021/11/15 16:49:20 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	char		*sorc;
	size_t		i;

	sorc = (char *)src;
	dest = (char *)dst;
	i = 0;
	if (dst != 0 || src != 0)
	{
		while (i < n)
		{
			dest[i] = sorc[i];
			i++;
		}
	}
	return (dst);
}
