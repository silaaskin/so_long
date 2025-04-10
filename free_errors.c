/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:18:59 by saskin            #+#    #+#             */
/*   Updated: 2025/04/10 09:25:41 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_fonc(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	exit_simple_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (i < game->height)
	{
		if (game->map[i])
			free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

void	destroy_images(t_game *game)
{
	if (!game || !game->img)
		return ;
	if (game->img->player)
		mlx_destroy_image(game->mlx, game->img->player);
	if (game->img->coin)
		mlx_destroy_image(game->mlx, game->img->coin);
	if (game->img->wall)
		mlx_destroy_image(game->mlx, game->img->wall);
	if (game->img->ground)
		mlx_destroy_image(game->mlx, game->img->ground);
	if (game->img->exit)
		mlx_destroy_image(game->mlx, game->img->exit);
	free(game->img);
}

void	ft_free(t_game *game, int flg)
{
	int	i;

	i = 0;
	free_map(game);
	destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(flg);
}
