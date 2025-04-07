#include "so_long.h"
void check_map_rectangular(t_game *game)
{
	int row;
	row = 1;

	while (row < game->height)
	{
		if (ft_strlen(game->map[row]) != game->width)
			{
                ft_printf("ERROR\nMAP IS NOT RECTANGULAR");
                free_and_exit(game);
            }
		row++;
	}
}
int	check_top_bottom(int row, char **map)
{
	int	i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map_borders(t_game *game)
{
	int	i;

	i = 1;
	if (check_top_bottom(0, game->map) == 0 || check_top_bottom(game->height - 1, game->map) == 0)
    {
        ft_printf("ERROR\nMAP BORDER MUST BE MADE OF WALLS");
        free_and_exit(game);
    }
		
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][ft_strlen(game->map[0]) - 1] != '1')
        {
            ft_printf("ERROR\nMAP BORDER MUST BE MADE OF WALLS");
            free_and_exit(game);
        }
		i++;
	}
	return (1);
}
void check_valid_characters(t_game *game)
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
                    free_and_exit(game);
                }
			col++;
		}
		row++;
	}
}
void check_map(t_game *game)
{
    check_map_rectangular(game);
    check_map_borders(game);
    check_valid_characters(game);
}