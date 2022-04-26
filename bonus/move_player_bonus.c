/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:59:09 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/26 01:02:09 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long_bonus.h"

void lose_or_win(char tile, t_vars *data)
{
	if (tile == 'M')
	{
		ft_putendl_fd("OUCH, YOU LOST !!", 1);
		close_win(data);
	}
	else if (tile == 'E' && data->count == 0)
	{
		ft_putendl_fd("CONGRATS champ, you won !!", 1);
		close_win(data);
	}
}

void	move_down(t_vars *data)
{
	char tile;

	tile = data->map_arr[data->pos_y + 1][data->pos_x];
	if (tile != '1' && tile != 'E' && tile != 'M')
	{
		if (tile == 'C')
		{
			data->map_arr[data->pos_y + 1][data->pos_x] = '0';
			data->count--;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.bg,
			data->pos_x * 80, data->pos_y * 80);
		data->pos_y++;
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win,
			data->imgs.player, data->pos_x * 80, data->pos_y * 80);
		data->move_count++;
	}
	else
		lose_or_win(tile, data);
}

void	move_left(t_vars *data)
{
	char tile;

	tile = data->map_arr[data->pos_y][data->pos_x + 1];
	if (tile != '1' && tile != 'E' && tile != 'M')
	{
		if (tile == 'C')
		{
			data->map_arr[data->pos_y][data->pos_x + 1] = '0';
			data->count--;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.bg,
			data->pos_x * 80, data->pos_y * 80);
		data->pos_x++;
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win,
			data->imgs.player, data->pos_x * 80, data->pos_y * 80);
		data->move_count++;
	}
	else
		lose_or_win(tile, data);
}

void	move_up(t_vars *data)
{
	char tile;

	tile = data->map_arr[data->pos_y - 1][data->pos_x];
	if (tile != '1' && tile != 'E' && tile != 'M')
	{
		if (tile == 'C')
		{
			data->map_arr[data->pos_y - 1][data->pos_x] = '0';
			data->count--;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.bg,
			data->pos_x * 80, data->pos_y * 80);
		data->pos_y--;
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win,
			data->imgs.player, data->pos_x * 80, data->pos_y * 80);
		data->move_count++;
	}
	else
		lose_or_win(tile, data);
}

void	move_right(t_vars *data)
{
	char tile;

	tile = data->map_arr[data->pos_y][data->pos_x - 1];
	if (tile != '1' && tile != 'E' && tile != 'M')
	{
		if (tile == 'C')
		{
			data->map_arr[data->pos_y][data->pos_x - 1] = '0';
			data->count--;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.bg,
			data->pos_x * 80, data->pos_y * 80);
		data->pos_x--;
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win,
			data->imgs.player, data->pos_x * 80, data->pos_y * 80);
		data->move_count++;
	}
	else
		lose_or_win(tile, data);
}

void display_moves(t_vars *data)
{
	ft_putnbr_fd(data->move_count, 1);
	ft_putendl_fd(" moves, go on champ !!", 1);
	display_moves_in_win(data);
}

int	move_player(int key, t_vars *data)
{
	if (key == 53)
		close_win(data);
	if (key == DOWN_KEY || key == 125)
		move_down(data);
	if (key == LEFT_KEY || key == 124)
		move_left(data);
	if (key == UP_KEY || key == 126)
		move_up(data);
	if (key == RIGHT_KEY || key == 123)
		move_right(data);
	if (key != 53)
		display_moves(data);
	return (0);
}
