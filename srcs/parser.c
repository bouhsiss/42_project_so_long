/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:59:16 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/24 01:30:54 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long.h"

int	open_file(char *file)
{
	char	*ext;
	int		fd;

	if (open(file, O_DIRECTORY) > 0)
		error_message("Error : map should be a file not a directory");
	fd = open(file, O_RDONLY);
	ext = ft_strchr(file, '.');
	if (fd == -1)
		error_message("Error : file not found");
	if (ext == 0)
		error_message("Error : map file should have .ber extension");
	if (ft_strcmp(ext, ".ber"))
		error_message("Error : map file should have .ber extension");
	return (fd);
}

char	**parser(char *file, t_vars *data)
{
	int		fd;
	char	*temp;
	char	*p;
	char	**map;

	map = NULL;
	data->win.lines = 0;
	fd = open_file(file);
	temp = get_next_line(fd);
	p = temp;
	while (temp)
	{
		temp = get_next_line(fd);
		if (temp)
			p = ft_strjoin(p, temp);
		free(temp);
		data->win.lines++;
	}
	map = ft_split(p, '\n');
	is_map_valid(map, data->win.lines);
	free(p);
	return (map);
}
