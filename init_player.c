/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:18:07 by saskin            #+#    #+#             */
/*   Updated: 2025/04/11 00:11:38 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_element(char c, t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img->ground, x, y);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img->player, x, y);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->wall, x, y);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img->coin, x, y);
	if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->exit, x, y);
	}
}

void	render_map(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (game->map[i])
	{
		j = 0;
		x = 0;
		while (game->map[i][j])
		{
			put_element(game->map[i][j], game, x, y);
			j++;
			x += 64;
		}
		i++;
		y += 64;
	}
}

void	init_player(t_game *game, int i, int j)
{
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
			}
			if (game->map[i][j] == 'E')
			{
				game->exit_x = i;
				game->exit_y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (check_coins(game) == 0)
		error_flood_fill(game);
}

void	error_flood_fill(t_game *game)
{
	remove_collected(game);
	ft_printf("Error\nGame cannot finish\n");
	ft_free(game, 1);
}
