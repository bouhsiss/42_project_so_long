/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:58:51 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/26 01:02:05 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long_bonus.h"

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

void display_moves_in_win(t_vars *data)
{
	void *bg;


	bg = create_img(data, "./assets/moves_bg.xpm");
	mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, bg, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win.mlx_win, 35, 35, 0x00FFFFFF, ft_itoa(data->move_count));
}

int	close_win(t_vars *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win.mlx_win);
	free(data);
	exit(0);
}
