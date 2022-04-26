/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:58:51 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/26 02:02:18 by hbouhsis         ###   ########.fr       */
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

void	lose_or_win(char tile, t_vars *data)
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

void	display_moves(t_vars *data)
{
	ft_putnbr_fd(data->move_count, 1);
	ft_putendl_fd(" moves, go on champ !!", 1);
	display_moves_in_win(data);
}

void	display_moves_in_win(t_vars *data)
{
	void	*bg;
	char	*moves;

	moves = ft_itoa(data->move_count);
	bg = create_img(data, "./assets/moves_bg.xpm");
	mlx_put_image_to_window(data->mlx_ptr, data->win.mlx_win, bg, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win.mlx_win, 35, 35, 0x00FFFFFF, moves);
	free(moves);
}

int	close_win(t_vars *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx_ptr, data->win.mlx_win);
	while (data->map_arr[i])
	{
		free(data->map_arr[i]);
		i++;
	}
	free(data->map_arr);
	free(data);
	system("leaks so_long");
	exit(0);
}
