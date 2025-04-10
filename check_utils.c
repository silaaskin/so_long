/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:22:43 by saskin            #+#    #+#             */
/*   Updated: 2025/04/10 11:39:41 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strcspn(const char *s, const char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (charset[j])
		{
			if (s[i] == charset[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	check_valid_characters(t_game *game)
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
			if (current != '1' && current != '0'
				&& current != 'P' && current != 'C' && current != 'E')
			{
				ft_printf("Error\nInvalid character in map");
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

void	check_map(t_game *game)
{
	if (game->height < 3)
	{
		ft_printf("Error\nWrong map size\n");
		ft_free(game, 1);
	}
	if (check_map_borders(game) || number_of_characters(game)
		|| check_valid_characters(game) || check_map_rectangular(game))
	{
		ft_free(game, 1);
		exit(1);
	}
}

void	arg_check(int argc, char **argv)
{
	int	fd;
	int	len;

	if (argc != 2 || !argv[1] || argv[1][0] == '\0')
		exit_simple_error("Error\nWrong arguments");
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(&argv[1][len - 4], ".ber", 4) != 0
		|| argv[1][len - 5] == '/')
		exit_simple_error("Error\nFiles is not a .ber\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_simple_error("Error\nFile cannot open");
	close(fd);
}
