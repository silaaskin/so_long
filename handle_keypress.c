/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:21:27 by saskin            #+#    #+#             */
/*   Updated: 2025/04/10 10:14:44 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	if (keycode == 65307)
	{
		close_frame(game);
	}
	else if (keycode == 100)
	{
		move_player(game, game->player_x, game->player_y + 1);
	}
	else if (keycode == 97)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == 119)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == 115)
		move_player(game, game->player_x + 1, game->player_y);
	render_map(game);
	return (keycode);
}

int	close_frame(t_game *game)
{
	ft_free(game, 1);
	return (0);
}
