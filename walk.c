/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:42:02 by saskin            #+#    #+#             */
/*   Updated: 2025/04/11 01:22:00 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_score(t_game *game)
{
	ft_printf("moves:%d\n", game->moves);
}

static void	prepare_to_end(t_game *game)
{
	game->moves++;
	print_score(game);
	ft_printf("Win!\n");
	close_frame(game);
}

static void	update_position(t_game *game, int new_x, int new_y)
{
	game->map[game->player_x][game->player_y] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_x][new_y] = 'P';
}

static void	enter_exit_cell(t_game *game, int new_x, int new_y, int *a)
{
	game->map[game->player_x][game->player_y] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_x][new_y] = 'P';
	*a = 1;
}

void	move_player(t_game *game, int new_x, int new_y)
{
	static int	a = 0;

	if (new_x < 0 || new_x >= game->height || new_y < 0 || new_y >= game->width)
		return ;
	if (a == 1 && game->map[new_x][new_y] != '1')
	{
		if (game->map[new_x][new_y] == 'C')
			game->coin_cnt--;
		game->map[game->player_x][game->player_y] = 'E';
		game->map[new_x][new_y] = 'P';
		game->player_x = new_x;
		game->player_y = new_y;
		a = 0;
	}
	if (game->coin_cnt == 0 && game->map[new_x][new_y] == 'E')
		prepare_to_end(game);
	else if (game->map[new_x][new_y] == 'C')
		game->coin_cnt--;
	else if (game->map[new_x][new_y] == '1')
		return ;
	if (game->coin_cnt != 0 && game->map[new_x][new_y] == 'E')
		enter_exit_cell(game, new_x, new_y, &a);
	++game->moves;
	print_score(game);
	update_position(game, new_x, new_y);
}
