/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:51:48 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/03/23 18:50:54 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		sz;

	sz = ft_strlen(s1);
	s2 = (char *)malloc(sz * sizeof (char) + 1);
	if (!(s2))
		return (0);
	ft_memcpy(s2, s1, sz);
	s2[sz] = '\0';
	return (s2);
}
