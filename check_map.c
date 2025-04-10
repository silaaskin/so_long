/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:19:05 by saskin            #+#    #+#             */
/*   Updated: 2025/04/10 11:35:44 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_top_bottom(int row, char **map)
{
	int	i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_map_rectangular(t_game *game)
{
	int	row;

	row = 1;
	while (row < game->height)
	{
		if ((int)ft_strlen(game->map[row]) != game->width)
		{
			ft_printf("ERROR\nMap is not rectangular");
			return (1);
		}
		row++;
	}
	return (0);
}

int	check_map_borders(t_game *game)
{
	int	i;

	i = 1;
	if (check_top_bottom(0, game->map)
		|| check_top_bottom(game->height - 1, game->map))
	{
		ft_printf("Error\nMap border must be made of walls");
		return (1);
	}
	while (i < game->height)
	{
		if (game->map[i][0] != '1'
			|| game->map[i][ft_strlen(game->map[0]) - 1] != '1')
		{
			ft_printf("Error\nMap border must be made of walls");
			return (1);
		}
		i++;
	}
	return (0);
}

static void	counter(t_game *game, char current)
{
	if (current == 'P')
		game->p_cnt++;
	if (current == 'C')
		game->coin_cnt++;
	if (current == 'E')
		game->end_cnt++;
}

int	number_of_characters(t_game *game)
{
	int		row;
	int		col;
	char	current;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			current = game->map[row][col];
			counter(game, current);
			col++;
		}
		row++;
	}
	if (game->p_cnt != 1 || game->coin_cnt < 1 || game->end_cnt != 1)
	{
		ft_printf("Error\nWrong number of characters");
		return (1);
	}
	return (0);
}
