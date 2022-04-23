#include"so_long.h"


void error_message(char *error)
{
	ft_putstr_fd("Error :", 2);
	ft_putendl_fd(error, 2);
	exit(0);
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