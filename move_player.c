#include"so_long.h"

void move_down(t_vars *data)
{
	if (data->map_arr[data->pos_y+1][data->pos_x] != '1' &&
		data->map_arr[data->pos_y+1][data->pos_x] != 'E')
	{
		if (data->map_arr[data->pos_y + 1][data->pos_x] == 'C')
		{
			data->map_arr[data->pos_y + 1][data->pos_x] = '0';
			data->count--;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.bg, data->pos_x*80, data->pos_y*80);
		data->pos_y++;
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.player, data->pos_x*80, data->pos_y*80);
	}
	if (data->map_arr[data->pos_y+1][data->pos_x] == 'E' && data->count == 0)
		close_win(data);
}

void move_left(t_vars *data)
{
	if (data->map_arr[data->pos_y][data->pos_x + 1] != '1' &&
		data->map_arr[data->pos_y][data->pos_x + 1] != 'E')
	{
		if (data->map_arr[data->pos_y][data->pos_x + 1] == 'C')
		{
			data->map_arr[data->pos_y][data->pos_x + 1] = '0';
			data->count--;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.bg, data->pos_x*80, data->pos_y*80);
		data->pos_x++;
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.player, data->pos_x*80, data->pos_y*80);
	}
	if (data->map_arr[data->pos_y][data->pos_x + 1] == 'E' && data->count == 0)
		close_win(data);
}

void move_up(t_vars *data)
{
	if (data->map_arr[data->pos_y-1][data->pos_x] != '1' &&
		data->map_arr[data->pos_y-1][data->pos_x] != 'E')
	{
		if (data->map_arr[data->pos_y - 1][data->pos_x] == 'C')
		{
			data->map_arr[data->pos_y - 1][data->pos_x] = '0';
			data->count--;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.bg, data->pos_x*80, data->pos_y*80);
		data->pos_y--;
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.player, data->pos_x*80, data->pos_y*80);
	}
	if (data->map_arr[data->pos_y-1][data->pos_x] == 'E' && data->count == 0)
		close_win(data);
}

void move_right(t_vars *data)
{
	if (data->map_arr[data->pos_y][data->pos_x-1] != '1' && 
		data->map_arr[data->pos_y][data->pos_x-1] != 'E')
	{
		if (data->map_arr[data->pos_y][data->pos_x-1] == 'C')
		{
			data->map_arr[data->pos_y][data->pos_x-1] = '0';
			data->count--;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.bg, data->pos_x*80, data->pos_y*80);
		data->pos_x--;
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.player, data->pos_x*80, data->pos_y*80);
	}
	if (data->map_arr[data->pos_y][data->pos_x-1] == 'E' && data->count == 0)
		close_win(data);
}

int move_player(int key, t_vars *data)
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
	return (0);
}

int close_win(t_vars *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win.mlx_win);
	free(data);
	exit(0);
}