/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:58:51 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/26 02:06:43 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long.h"

void	print_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("line %d   %s\n", i, arr[i]);
		i++;
	}
}

int	close_win(t_vars *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx_ptr, data->win.mlx_win);
	while (data->map_arr[i])
	{
		free(data->map_arr[i]);
		i++;
	}
	free(data->map_arr);
	free(data);
	exit(0);
}
