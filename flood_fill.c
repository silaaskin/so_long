/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 02:12:00 by saskin            #+#    #+#             */
/*   Updated: 2025/04/10 10:13:25 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_coins(t_game *game)
{
	char	**temp_map;
	int		i;
	int		can_e;

	i = 0;
	temp_map = ft_calloc(game->height + 1, sizeof(char *));
	if (!temp_map)
		return (0);
	while (i < game->height)
	{
		temp_map[i] = ft_strdup(game->map[i]);
		if (!temp_map[i])
		{
			free_fonc(temp_map);
			return (0);
		}
		i++;
	}
	temp_map[i] = NULL;
	flood_fill(temp_map, game, game->player_x, game->player_y);
	free_fonc(temp_map);
	can_e = game->can_exit;
	return ((game->collected == game->coin_cnt) && can_e);
}

void	remove_collected(t_game *game)
{
	game->can_exit = 0;
	game->collected = 0;
}

void	flood_fill(char **map, t_game *game, int x, int y)
{
	int		cols;

	cols = ft_strlen(game->map[0]);
	if (x < 0 || y < 0 || x >= game->height || y >= cols
		|| map[x][y] == '1' || map[x][y] == 'V')
		return ;
	if (map[x][y] == 'C')
		game->collected++;
	if (map[x][y] == 'E')
	{
		if ((x > 0 && map[x - 1][y] != '1' && map[x - 1][y] != 'E') ||
			(x < game->height - 1 && map[x + 1][y] != '1' &&
			map[x + 1][y] != 'E') ||
			(y > 0 && map[x][y - 1] != '1' && map[x][y - 1] != 'E') ||
			(y < cols - 1 && map[x][y + 1] != '1' && map[x][y + 1] != 'E'))
			game->can_exit = 1;
		return ;
	}
	map[x][y] = 'V';
	flood_fill(map, game, x + 1, y);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x, y - 1);
}
