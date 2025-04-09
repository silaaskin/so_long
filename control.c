/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:18:37 by saskin            #+#    #+#             */
/*   Updated: 2025/04/09 03:46:25 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void xpm_control(void)
{
    int fd_coin;
    int fd_exit;
    int fd_ground;
    int fd_wall;
    int fd_player;
    fd_coin = open("./textures/coin.xpm", O_RDWR);
    fd_exit = open("./textures/exit.xpm", O_RDWR);
    fd_ground = open("./textures/ground.xpm", O_RDWR);
    fd_wall = open("./textures/wall.xpm", O_RDWR);
    fd_player = open("./textures/player.xpm", O_RDWR);
    if(fd_coin <= 0 || fd_exit <= 0 || fd_ground <= 0 || fd_wall <= 0 || fd_player <= 0)
    {
        write(1, "Missing XPM File\n", 18);
		close(fd_coin);
		close(fd_exit);
		close(fd_ground);
		close(fd_wall);
        close(fd_player);
		exit(1);
    }
}
void init_images(t_game *game)
{
    game->img = ft_calloc(1, sizeof(t_img)); 
    if(!game->img)
    {
        free_map(game);
		exit (1);
    }
	if (get_img(game, 0, 0)) {

		ft_printf("%s", "xpm not found");
		destroy_all(game);
		exit (1);
	}
	game->coin_cnt = 0;
	game->p_cnt = 0;
	game->moves = 0;
	game->end_cnt = 0;
	
    
}
int get_img(t_game *game, int x, int y)
{
    game->img->height  = game->height * 64;
    game->img->width = game->width * 64;
    game->mlx = mlx_init();
    game->player_x = 0;
    game->player_y = 0;
    game->collected = 0;
    game->img->player =  mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm", &x, &y);
    game->img->coin =  mlx_xpm_file_to_image(game->mlx, "./textures/coin.xpm", &x, &y);
    game->img->wall =  mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &x, &y);
    game->img->ground =  mlx_xpm_file_to_image(game->mlx, "./textures/ground.xpm", &x, &y);
    game->img->exit =  mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &x, &y);
	game->win = mlx_new_window(game->mlx, game->img->width, game->img->height, "so_long");
    if(!game->img->player || !game->img->wall || !game->img->coin || !game->img->exit || !game->img->ground )
        return 1;
    return 0;
}
void	put_element(char c, t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img->ground, x, y);
	if (c == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		mlx_put_image_to_window(game->mlx, game->win, game->img->player, x, y);
	}
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->wall, x, y);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img->coin, x, y);
	if (c == 'E')
	{
		game->exit_x = x;
		game->exit_y = y;
		mlx_put_image_to_window(game->mlx, game->win, game->img->exit, x, y);
	}
}

void	put_score(t_game *game)
{
	char	*score;

	score = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFFFF, score);
	free(score);
}

void	render_map(t_game *game)
{
	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			put_element(game->map[i][j], game, i * 64, j * 64);
			j++;
            if (check_coins(game) == 0)
	        error_flood_fill(game);
			put_score(game->win);
		}
		i++;
	}
}
void error_flood_fill(t_game *game)
{
    destroy_all(game);
    ft_printf("Game cannot finish\n");
	exit (1);
}
