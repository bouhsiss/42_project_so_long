/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:58:28 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/25 03:01:18 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long_bonus.h"

void	error_message(char *error)
{
	ft_putendl_fd(error, 2);
	exit(0);
}

void	wall_checker(char **map, int lines)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (i < len)
	{
		if (map[0][i] != '1' || map[lines -1][i] != '1')
			error_message("Error : map_not_valid");
		i++;
	}
	if (ft_strlen(map[0]) != ft_strlen(map[lines - 1]))
		error_message("Error : map_not_valid");
}

void	flags_check(char **map, int lines)
{
	int	e;
	int	c;
	int	p;

	e = 0;
	p = 0;
	c = 0;
	lines = lines - 1;
	while (lines)
	{
		if (ft_strchr(map[lines], 'C'))
			c = 1;
		if (ft_strchr(map[lines], 'E'))
			e++;
		if (ft_strchr(map[lines], 'P'))
			p++;
		lines--;
	}
	if ((c * p * e) != 1)
		error_message("Error : map_not_valid");
}

void char_checker(char **map)
{
	int	i;
	int	j;
	char c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			c = map[i][j];
			if(c != '1' && c != '0' && c != 'E' && c != 'P' && c != 'C' && c != 'M')
			{
				error_message("Error : character not valid");
			}
			j++;
		}
		i++;
	}
	
}

void	is_map_valid(char **map, int lines)
{
	int	i;
	int	len;
	int	j;

	i = 1;
	j = 0;
	len = ft_strlen(map[0]);
	flags_check(map, lines);
	wall_checker(map, lines);
	char_checker(map);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i - 1]))
			error_message("Error : map_not_valid");
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			error_message("Error : map_not_valid");
		i++;
	}
}
