/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:18:46 by saskin            #+#    #+#             */
/*   Updated: 2025/04/09 03:07:50 by saskin           ###   ########.fr       */
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
}

void	create_map(char *file_path, t_game *game)
{
	game->height = get_line_count(file_path);
	ft_printf("Height: %d\n", game->height);


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
	int		fd;

	if (argc != 2)
		exit_simple_error("ERROR\nWRONG ARGUMENTS");

	if (ft_strlen(argv[1]) < 5 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
        exit_simple_error("ERROR\nFILE IS NOT A .ber");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_simple_error("ERROR\nFILE CANNOT OPEN");

	close(fd);
}

// int	main(int argc, char **argv)
// {
// 	t_game	*game;
	
// 	xpm_control();
// 	arg_check(argc, argv);
// 	game = ft_calloc(1, sizeof(t_game));
// 	create_map(argv[1], game);
// 	check_map(game);
// 	init_images(game);
// 	mlx_hook(game->win, 2, (1L << 0), handle_keypress, game);
// 	mlx_hook(game->win, 17, 0, close_frame, game);
// 	mlx_loop(game->mlx);
// }
int	main(int argc, char **argv)
{
	t_game	*game;
	
	ft_printf("step 1: xpm kontrol\n");
	xpm_control();

	ft_printf("step 2: arg kontrol\n");
	arg_check(argc, argv);

	ft_printf("step 3: calloc\n");
	game = ft_calloc(1, sizeof(t_game));

	ft_printf("step 4: create_map\n");
	create_map(argv[1], game);

	ft_printf("step 5: check_map\n");
	check_map(game);

	init_images(game);
	ft_printf("step 6: init_images\n");
	render_map(game);
	ft_printf("step 7: hook ve loop başlıyor\n");
	mlx_hook(game->win, 2, (1L << 0), handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_frame, game);
	mlx_loop(game->mlx);
}