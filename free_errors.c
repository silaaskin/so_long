/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:18:59 by saskin            #+#    #+#             */
/*   Updated: 2025/04/09 04:12:35 by saskin           ###   ########.fr       */
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
void	free_and_exit(t_game *game)
{
	free_map(game);
	exit(1);
}
void free_map(t_game *game)
{
    int i;
 
    if (!game->map)
        return;

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
void destroy_images(t_game *game)
{
    if (!game || !game->img)
        return;

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
void destroy_all(t_game *game)
{
		if (!game)
			return;
	
		destroy_images(game);
	
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
	
		mlx_destroy_display(game->mlx);
	
		if (game->mlx)
		{
			free(game->mlx);
			game->mlx = NULL;
		}

		free_map(game);
}	
	