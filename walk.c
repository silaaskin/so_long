/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:42:02 by saskin            #+#    #+#             */
/*   Updated: 2025/04/09 02:07:11 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_score(t_game *game)
{
	ft_printf("%d\n", game->moves);
}
void	move_player(t_game *game, int new_x, int new_y)
{
    if (game->coin_cnt== 0 && game->map[new_x / 32][new_y / 32] == 'E')
	{
		game->moves += 1;
		print_score(game);
		ft_printf("Win!");
		close_frame(game);
	}
	if (game->map[new_y / 32][new_x / 32] != '1' &&
		game->map[new_y / 32][new_x / 32] != 'E')
	{
		game->map[game->player_y / 32][game->player_x / 32] = '0';
		game->map[new_y / 32][new_x / 32] = 'P';
		game->player_x = new_x;
		game->player_y = new_y;

		if (game->map[new_y / 32][new_x / 32] == 'C')
		{
			game->coin_cnt--;
		}
		game->moves++;
	}
}

int	handle_keypress(int keycode, t_game *game)
{

	mlx_clear_window(game->mlx, game->win);
	if (keycode == 2)
		move_player(game, game->player_x + 32, game->player_y);
	else if (keycode == 0)
		move_player(game, game->player_x - 32, game->player_y);
	else if (keycode == 13)
		move_player(game, game->player_x, game->player_y - 32);
	else if (keycode == 1)
		move_player(game, game->player_x, game->player_y + 32);
	else if (keycode == 53)
		close_frame(game);

	render_map(game);
	return (keycode);
}
int close_frame(t_game *game)
{
    destroy_images(game);
    free_map(game);
    mlx_destroy_window(game->mlx, game->win);
	exit(1);
}