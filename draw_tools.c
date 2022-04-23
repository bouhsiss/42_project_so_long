#include"so_long.h"

void *create_img(t_vars *data, char *path)
{
	int x;
	int y;

	x = 0;
	y = 0;
	return(mlx_xpm_file_to_image(data->mlx_ptr, path, &x, &y));
}

void draw_tile(char tile, t_vars *data, int w, int h)
{
	if (tile == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.wall, w, h);
	else if (tile == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.collectible, w, h);
		data->count++;	
	}
	else if (tile == 'P')
	{
		data->pos_x = w/80;
		data->pos_y = h/80;
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.player, w, h);
	}
	else if (tile == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.exit, w, h);

}


void draw_map(t_vars *data)
{
	int i;
	int j;
	int h;
	int  w;

	h = 0;
	i = 0;
	data->count = 0;
	while(data->map_arr[i])
	{
		j = 0;
		w = 0;
		while(data->map_arr[i][j])
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, data->imgs.bg, w, h);
			draw_tile(data->map_arr[i][j], data, w, h);
			w += 80;
			j++;
		}
		h += 80;
		i++;
	}
}

