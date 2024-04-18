CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -lX11 -lXext -lm


NAME = so_long.exe

SRCS = src/so_long.c \
	src/checks.c \
	src/img.c \
	src/left_walk.c \
	src/main.c \
	src/map.c \
	src/move_down.c \
	src/move_exit.c \
	src/move_left.c \
	src/move_right.c \
	src/move_up.c \
	src/playertiles.c \
	src/right_walk.c \
	src/tiles.c \
	src/tiles_rev.c \
	src/utils.c \
	src/win_or_lose.c

all: $(NAME)

$(NAME):
	@make all -C $(LIBFT_DIR)
	@make all -C $(MLX_DIR)
	@$(CC) -fPIE $(CFLAGS) $(SRCS) $(MLX) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "Let's play !!"

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	@rm -f $(NAME)

re: fclean all

replay:
	@rm -f $(NAME)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "Let's play !!"

.PHONY: all clean fclean re replay
