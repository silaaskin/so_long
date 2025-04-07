
#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_H 32
# define IMG_W 32

# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
// # include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_game
{
	void *mlx;
	void *win;
	char **map;
	int width;
	int height;
	int player_x;
	int player_y;
	int collectibles;
	int collected;
	int moves;
	int exit_x;
	int exit_y;
	int fd;

	void	*wall;
    void	*empty;
    void	*player;
    void	*collectible;
    void	*exit;
}t_game;

typedef struct s_img {
    void    *img;
    int     width;
    int     height;
} t_img;


#endif