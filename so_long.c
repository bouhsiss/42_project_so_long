#include"so_long.h"

int main(int ac, char **av)
{
	t_vars *data;

	data = malloc(sizeof(t_vars));
	if (ac == 2)
	{
		data->map_arr = parser(av[1]);
		execute_map(data);		
	}
}