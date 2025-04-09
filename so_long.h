/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:18:52 by saskin            #+#    #+#             */
/*   Updated: 2025/04/09 04:16:58 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H



# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_img {
    int     width;
    int     height;
	void	*wall;
    void	*ground;
    void	*player;
    void	*coin;
    void	*exit;
} t_img;

typedef struct s_game
{	
	void *mlx;
	char **map;
	int width;
	int height;
	int player_x;
	int player_y;
	int collectibles;
	int collected;
	int moves;
	int exit_x;
	int exit_y;
	int fd;
	int		p_cnt;
	int		end_cnt;
	int		coin_cnt;
	void *win;
	t_img *img;
	int		can_exit;
}t_game;

int check_map_rectangular(t_game *game);
int	check_top_bottom(int row, char **map);
int	check_map_borders(t_game *game);
int number_of_characters(t_game *game);
int check_valid_characters(t_game *game);
void check_map(t_game *game);
void xpm_control(void);
void init_images(t_game *game);
void xpm_control(void);
void init_images(t_game *game);
int get_img(t_game *game, int x, int y);
void	put_element(char c, t_game *game, int x, int y);
void	put_score(t_game *game);
void	render_map(t_game *game);
void error_flood_fill(t_game *game);
int	check_coins(t_game *game);
void	remove_collected(t_game *game);
void	flood_fill(char **map, t_game *game, int x, int y);
void	exit_simple_error(char *str);
void	free_fonc(char **map);
void	free_and_exit(t_game *game);
void	free_map(t_game *game);
void destroy_images(t_game *game);
void destroy_all(t_game *game);
int	get_line_count(const char *file_path);
void	read_map_line(t_game *game, int row);
void	create_map(char *file_path, t_game *game);
void	arg_check(int argc, char **argv);
void	*ft_calloc(size_t count, size_t size);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	print_score(t_game *game);
void	move_player(t_game *game, int new_x, int new_y);
int	handle_keypress(int keycode, t_game *game);
int close_frame(t_game *game);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
size_t sstrlen(const char *s);
#endif