#include"so_long.h"

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
			p = ft_strjoin(p, temp);
		free(temp);
		lines++;
	}
	map = ft_split(p, '\n');
	is_map_valid(map, lines);
	free(p);
	return(map);
}
