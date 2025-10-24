NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INCLUDE_DIR = include
SRC_DIR     = src
LIBFT_DIR   = libft
MLX42_DIR   = MLX42

LIBFT_LIB   = $(LIBFT_DIR)/libft.a
MLX42_LIB   = $(MLX42_DIR)/build/libmlx42.a
INCLUDES    = -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(MLX42_DIR)/include

SRCS = $(SRC_DIR)/so_long.c \
        $(SRC_DIR)/ft_render_game.c \
        $(SRC_DIR)/ft_map.c \
        $(SRC_DIR)/ft_key_hand.c \
        $(SRC_DIR)/ft_game_init.c \
        $(SRC_DIR)/ft_free_and_clean.c \
        $(SRC_DIR)/ft_check_path.c \
        $(SRC_DIR)/ft_check_map.c

OBJS = $(SRCS:.c=.o)

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
    MLX42_FLAGS = -ldl -lglfw -pthread -lm
endif

ifeq ($(UNAME), Darwin)
    MLX42_FLAGS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
endif

all: deps $(NAME)

deps:
ifeq ($(UNAME), Linux)
	@which cmake > /dev/null || (echo "Installing cmake..." && sudo apt-get update && sudo apt-get install -y cmake)
	@which pkg-config > /dev/null || (echo "Installing pkg-config..." && sudo apt-get install -y pkg-config)
	@pkg-config --exists glfw3 || (echo "Installing GLFW3..." && sudo apt-get install -y libglfw3-dev)
else ifeq ($(UNAME), Darwin)
	@which brew > /dev/null || (echo "Homebrew not found. Please install it first: https://brew.sh" && exit 1)
	@brew list cmake >/dev/null 2>&1 || (echo "Installing cmake..." && brew install cmake)
	@brew list glfw >/dev/null 2>&1 || (echo "Installing glfw..." && brew install glfw)
endif

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX42_LIB): deps
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build -DDEBUG=1 >/dev/null
	@$(MAKE) -C $(MLX42_DIR)/build -j$(nproc)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX42_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX42_LIB) $(MLX42_FLAGS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX42_DIR)/build

re: fclean all

.PHONY: all clean fclean re deps
