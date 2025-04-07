#include "so_long.h"

// void	exit_with_error(char *msg, t_data *data)
// {
// 	if (data)
// 	{
// 		if (data->map.map)
// 			free_fonc(data->map.map);
// 		free(data);
// 	}
// 	ft_printf("%s\n", msg);
// 	exit(1);
// }
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
	// cleanup_mlx(game);
	exit(1);
}
void	free_map(t_game *game)
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