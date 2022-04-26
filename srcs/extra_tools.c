/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:58:51 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/24 01:30:26 by hbouhsis         ###   ########.fr       */
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
	mlx_destroy_window(data->mlx_ptr, data->win.mlx_win);
	free(data);
	exit(0);
}
