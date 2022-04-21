#ifndef SO_LONG_H
# define SO_LONG_H

# include<mlx.h>
# include"./libft/libft.h"

typedef struct s_imgs
{
	void *bg;
	void *collectible;
	void *exit;
	void *wall;
	void *player;
}				t_imgs;
typedef struct s_vars
{
	void *mlx_ptr;
	void *mlx_win;
	t_imgs imgs;
	char **map_arr;
}				t_vars;

#endif