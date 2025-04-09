/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:19:05 by saskin            #+#    #+#             */
/*   Updated: 2025/04/09 04:16:20 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int check_map_rectangular(t_game *game)
{
	int row;

	row = 1;
	while (row < game->height)
	{
		printf("%d\n", game->width);
		printf("%d\n", (int)ft_strlen(game->map[row]));
		if ((int)sstrlen(game->map[row]) != game->width)
			{
                ft_printf("ERROR\nMAP IS NOT RECTANGULAR");
				return (1);
            }
		row++;
	}
	return (0);
}

int	check_top_bottom(int row, char **map)
{
	int	i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_map_borders(t_game *game)
{
	int	i;

	i = 1;
	if (check_top_bottom(0, game->map) || check_top_bottom(game->height - 1, game->map))
    {
		ft_printf("ERROR\nMAP BORDER MUST BE MADE OF WALLS1");
		return 1;
    }
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][ft_strlen(game->map[0]) - 2] != '1')
        {
            ft_printf("ERROR\nMAP BORDER MUST BE MADE OF WALLS2");
            return 1;
        }
		i++;

	}
	return (0);
}
int number_of_characters(t_game *game)
{
	int row;
	int col;
	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			char current = game->map[row][col];
			if(current == 'P')
				game->p_cnt++;
			if(current == 'C')
				game->coin_cnt++;
			if(current == 'E')
				game->end_cnt++;
			col++;
		}
		row++;
	}
	if(game->p_cnt != 1 && game->coin_cnt < 1 && game->end_cnt != 1)
	{
		ft_printf("WRONG NUMBER OF CHARACTERS");
		return 1;
	}
	return 0;
}
int check_valid_characters(t_game *game)
{
	int row;
	int col;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			char current = game->map[row][col];
			if (current != '1' && current != '0' && current != 'P' && current != 'C' && current != 'E')
				{
                    ft_printf("ERROR\nINVALID CHARACTER IN MAP");
                    return 1;
				}
			col++;
		}
		row++;
	}
	return 0;
}
void check_map(t_game *game)
{
    if(check_map_borders(game) || number_of_characters(game) || check_valid_characters(game) || check_map_rectangular(game))
	{
		free_map(game);
		free(game);
		exit (1);
	}
}