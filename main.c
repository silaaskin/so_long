#include "so_long.h"
int	get_line_count(const char *file_path)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR: Could not open file\n");
		return (-1);
	}
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	read_map_line(t_game *game, int row)
{
	char	*line;
	int		col;

	col = 0;
	line = get_next_line(game->fd);
	while (line)
	{
		game->map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		game->width = ft_strlen(line);
		if (!game->map[row])
			free_and_exit(game);
		while (line[col] != '\0')
			game->map[row][col++] = line[col];
		game->map[row][col] = '\0';
		free(line);
		line = get_next_line(game->fd);
		row++;
		col = 0;
	}
}

void	create_map(const char *file_path, t_game *game)
{
	game->height = get_line_count(file_path);
	if (game->height == -1)
		free_and_exit(game);
	// game->map.path = file_path;
	game->map = ft_calloc(game->height + 1, sizeof(char *));
	if (!game->map)
		free_and_exit(game);
	game->fd = open(file_path, O_RDONLY);
	if (game->fd < 0)
	{
		ft_printf("ERROR\nFILE CANNOT OPEN");
		free_and_exit(game);
	}
	read_map_line(game, 0);
	close(game->fd);
}
void	arg_check(int argc, char **argv)
{
	int		i;
	int		fd;

	if (argc != 2)
		exit_simple_error("ERROR\nWRONG ARGUMENTS");

	i = 0;
	if (ft_strlen(argv[1]) < 5 || ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber") != 0)
        exit_simple_error("ERROR\nFILE IS NOT A .ber");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_simple_error("ERROR\nFILE CANNOT OPEN");

	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	arg_check(argc, argv);
	game = malloc(sizeof(t_game));
	create_map(argv[1], game);
	check_map(game);

}