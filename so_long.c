#include"so_long.h"

void error_message(char *error)
{
	ft_putendl_fd(error, 2);
	exit(0);
}

void print_arr(char **arr)
{
	int i=0;
	
	while(arr[i])
	{
		printf("line %d   %s\n", i, arr[i]);
		i++;
	}
}

int open_file(char *file)
{
	char *ext;
	int fd;

	if (open(file, O_DIRECTORY) > 0)
		error_message("Error : map should be a file not a directory");
	fd = open(file,O_RDONLY);
	ext = ft_strchr(file, '.');
	if (ft_strcmp(ext, ".ber") != 0 || fd == -1)
		error_message("Error : map file should have .ber extension");
	return(fd);
}

void wall_checker(char **map, int lines)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(map[0]);
	while(i < len)
	{
		if (map[0][i] != '1' || map[lines -1][i] != '1')
			error_message("map_not_valid");
		i++;
	}
	if (ft_strlen(map[0]) != ft_strlen(map[lines-1]))
		error_message("map_not_valid");
}

void flags_check(char **map, int lines)
{
	int E;
	int C;
	int P;

	E = 0;
	P = 0;
	C = 0;
	lines = lines - 1;
	while(lines)
	{
		if(ft_strchr(map[lines], 'C'))
			C = 1;
		if(ft_strchr(map[lines], 'E'))
			E = 1;
		if(ft_strchr(map[lines], 'P'))
			P = 1;
		lines--;
	}
	if(!(C*P*E))
		error_message("map_not_valid");
}


void is_map_valid(char **map,int lines)
{
	int i;
	int len;
	int j;

	i = 1;
	j = 0;
	len = ft_strlen(map[0]);
	flags_check(map, lines);
	wall_checker(map,lines);
	while(map[i])
	{
		if(ft_strlen(map[i]) != ft_strlen(map[i -1]))
			error_message("map_not_valid");
		if(map[i][0] != '1' || map[i][len -1] != '1')
			error_message("map_not_valid");
		i++;
	}
}



char **parser(char *file)
{
	int fd;
	char *temp;
	char *p = NULL;
	int lines =0;
	char **map;

	map = NULL;
	fd = open_file(file);
	temp = get_next_line(fd);
	p = temp;
	while (temp)
	{
		temp = get_next_line(fd);
		if(temp)
			p = ft_strjoin(temp, p);
		free(temp);
		lines++;
	}
	map = ft_split(p, '\n');
	is_map_valid(map, lines);
	free(p);
	return(map);
}

void *create_img(t_vars *data, char *path)
{
	int x;
	int y;

	x = 0;
	y = 0;
	return(mlx_xpm_file_to_image(data->mlx_ptr, path, &x, &y));
}

void draw_bg(t_vars *data)
{
	int i;
	int j;
	int h;
	int  w;

	h = 0;
	i = 0;
	while(data->map_arr[i])
	{
		j = 0;
		w = 0;
		while(data->map_arr[i][j])
		{
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imgs.bg, w, h);
			w += 80;
			j++;
		}
		h += 80;
		i++;
	}
}

void draw_map(t_vars *data, int lines, int columns)
{
	lines = 0 ;
	columns = 0;
	draw_bg(data);
}

void init_imgs(t_vars *data, t_imgs *imgs)
{
	imgs->bg = create_img(data, "./assets/bg.xpm");
	imgs->collectible = create_img(data, "./assets/collectible.xpm");
	imgs->player = create_img(data, "./assets/character.xpm");
	imgs->wall = create_img(data, "./assets/forest1.xpm");
}

void execute_map(t_vars data)
{
	int lines;
	int columns;

	lines = sizeof(data.map_arr) + 1;
	columns = ft_strlen(data.map_arr[0]);
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, columns*80, lines*80, "so_long");
	init_imgs(&data, &data.imgs);
	draw_map(&data, lines, columns);
	mlx_loop(data.mlx_ptr);
}

//gotta initialize images and gotta send the pointer of data

int main(int ac, char **av)
{
	t_vars data;

	if (ac == 2)
	{

		data.map_arr = parser(av[1]);
		execute_map(data);
	}
}