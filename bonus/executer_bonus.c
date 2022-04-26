/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:58:45 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/25 03:03:01 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long_bonus.h"

void	init_imgs(t_vars *data, t_imgs *imgs)
{
	imgs->bg = create_img(data, "./assets/bg.xpm");
	imgs->collectible = create_img(data, "./assets/collectible.xpm");
	imgs->player = create_img(data, "./assets/player.xpm");
	imgs->wall = create_img(data, "./assets/wall.xpm");
	imgs->exit = create_img(data, "./assets/exit.xpm");
	imgs->monster = create_img(data, "./assets/monster.xpm");
}

void	execute_map(t_vars *data)
{
	data->win.columns = ft_strlen(data->map_arr[0]);
	data->mlx_ptr = mlx_init();
	data->win.mlx_win = mlx_new_window(data->mlx_ptr, data->win.columns * 80,
			data->win.lines * 80, "so_long");
	init_imgs(data, &data->imgs);
	draw_map(data);
	mlx_hook(data->win.mlx_win, 02, 1L << 0, move_player, data);
	mlx_hook(data->win.mlx_win, 17, 1L << 5, close_win, data);
	mlx_loop(data->mlx_ptr);
}
