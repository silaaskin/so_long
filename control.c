/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:18:37 by saskin            #+#    #+#             */
/*   Updated: 2025/04/10 11:34:05 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_control(void)
{
	int	fd_coin;
	int	fd_exit;
	int	fd_ground;
	int	fd_wall;
	int	fd_player;

	fd_coin = open("./textures/coin.xpm", O_RDONLY);
	fd_exit = open("./textures/exit.xpm", O_RDONLY);
	fd_ground = open("./textures/ground.xpm", O_RDONLY);
	fd_wall = open("./textures/wall.xpm", O_RDONLY);
	fd_player = open("./textures/player.xpm", O_RDONLY);
	if (fd_coin < 0 || fd_exit < 0 || fd_ground < 0
		|| fd_wall < 0 || fd_player < 0)
	{
		ft_printf("Error\nMissing XPM file\n");
		close_file(fd_exit, fd_ground, fd_wall, fd_player);
		exit(1);
	}
	close_file(fd_exit, fd_ground, fd_wall, fd_player);
}

void	close_file( int fd_exit, int fd_ground, int fd_wall, int fd_player)
{
	if (fd_exit >= 0)
		close(fd_exit);
	if (fd_ground >= 0)
		close(fd_ground);
	if (fd_wall >= 0)
		close(fd_wall);
	if (fd_player >= 0)
		close(fd_player);
}

void	init_images(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_img));
	if (!game->img)
		ft_free(game, 1);
	if (get_img(game, 0, 0))
	{
		ft_printf("%s", "Error\nXpm not found");
		ft_free(game, 1);
	}
	game->moves = 0;
	game->end_cnt = 0;
}

int	check_max_size(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_screen_size(game->mlx, &x, &y);
	if (!(game->height * 64 <= y && game->width * 64 <= x))
		return (0);
	return (1);
}

int	get_img(t_game *game, int x, int y)
{
	game->img->height = game->height * 64;
	game->img->width = game->width * 64;
	game->mlx = mlx_init();
	game->collected = 0;
	game->img->player = mlx_xpm_file_to_image(game->mlx,
			"./textures/player.xpm", &x, &y);
	game->img->coin = mlx_xpm_file_to_image(game->mlx,
			"./textures/coin.xpm", &x, &y);
	game->img->wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall.xpm", &x, &y);
	game->img->ground = mlx_xpm_file_to_image(game->mlx,
			"./textures/ground.xpm", &x, &y);
	game->img->exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm", &x, &y);
	game->win = mlx_new_window(game->mlx, game->img->width,
			game->img->height, "so_long");
	if (!game->img->player || !game->img->wall || !game->img->coin
		|| !game->img->exit || !game->img->ground)
		return (1);
	return (0);
}
