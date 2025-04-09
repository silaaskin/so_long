NAME = so_long
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
PRINTF = ft_printf/libftprintf.a

SRC = main.c check_map.c control.c flood_fill.c free_errors.c utils.c walk.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	make -C $(MLX_DIR) 
	cc $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX_FLAGS) $(PRINTF) -o $(NAME)

clean:
	make clean -C ft_printf
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	make clean -C ft_printf
	make clean -C $(MLX_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re