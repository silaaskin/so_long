/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:18:46 by saskin            #+#    #+#             */
/*   Updated: 2025/04/10 12:50:08 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_line_count(const char *file_path)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR\nCould not open file\n");
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

static void	allocate_map(t_game *game, char *line, int row)
{
	game->map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
	game->width = ft_strlen(line);
	if (!game->map[row])
	{
		free(line);
		ft_free(game, 1);
	}
}

void	read_map_line(t_game *game, int row)
{
	char	*line;
	int		col;

	col = 0;
	line = get_next_line(game->fd);
	while (line)
	{
		line[ft_strcspn(line, "\n")] = 0;
		allocate_map(game, line, row);
		while (line[col] != '\0')
		{
			game->map[row][col] = line[col];
			col++;
		}
		game->map[row][col] = '\0';
		free(line);
		line = get_next_line(game->fd);
		row++;
		col = 0;
	}
	if (line)
		free(line);
	game->map[row] = NULL;
}

void	create_map(char *file_path, t_game *game)
{
	game->height = get_line_count(file_path);
	if (game->height == -1)
		ft_free(game, 1);
	game->map = ft_calloc(game->height + 1, sizeof(char *));
	if (!game->map)
		ft_free(game, 1);
	game->fd = open(file_path, O_RDONLY);
	if (game->fd < 0)
	{
		ft_printf("Error\nFile cannot open");
		ft_free(game, 1);
	}
	read_map_line(game, 0);
	close(game->fd);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	xpm_control();
	arg_check(argc, argv);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		ft_printf("Error\nMemory allocation failed\n");
		return (1);
	}
	create_map(argv[1], game);
	check_map(game);
	init_player(game, 0, 0);
	init_images(game);
	if (!(check_max_size(game)))
	{
		ft_printf("Error\nWrong map size");
		ft_free(game, 1);
	}
	render_map(game);
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_frame, game);
	mlx_loop(game->mlx);
}
