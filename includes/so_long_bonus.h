/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 02:07:05 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/26 02:23:13 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include<mlx.h>
# include"../libft/libft.h"

# define DOWN_KEY 1
# define LEFT_KEY 2
# define UP_KEY 13
# define RIGHT_KEY 0

typedef struct s_imgs
{
	void	*bg;
	void	*collectible;
	void	*exit;
	void	*wall;
	void	*player;
	void	*monster;
}				t_imgs;
typedef struct s_win
{
	void	*mlx_win;
	int		columns;
	int		lines;
}				t_win;

typedef struct s_vars
{
	void	*mlx_ptr;
	t_win	win;
	t_imgs	imgs;
	char	**map_arr;
	int		count;
	int		pos_x;
	int		pos_y;
	int		move_count;
}				t_vars;

void	error_message(char *error);
void	wall_checker(char **map, int lines);
void	flags_check(char **map, int lines);
void	is_map_valid(char **map, int lines);
void	*create_img(t_vars *data, char *path);
void	draw_tile(char tile, t_vars *data, int w, int h);
void	draw_map(t_vars *data);
void	init_imgs(t_vars *data, t_imgs *imgs);
void	execute_map(t_vars *data);
void	print_arr(char **arr);
int		open_file(char *file);
char	**parser(char *file, t_vars *data);
int		move_player(int key, t_vars *data);
int		close_win(t_vars *data);
void	display_moves_in_win(t_vars *data);
void	lose_or_win(char tile, t_vars *data);
void	display_moves(t_vars *data);

#endif
