NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -MMD
RM = rm -rf

SRCBAZ = main error struct_init struct_tiles_init \
	parsing map_init check_map flood_fill elem_pos \
	start_game ft_xpm events_hook tiles move mlx_closing game_end

SRC = $(addsuffix .c, $(addprefix sources/, $(SRCBAZ)))
SRCADD = $(SRCBAZ)
SRCBONUS = $(addsuffix _bonus.c, $(addprefix sources_bonus/, $(SRCADD)))

OBJ_DIR = obj
OBJ = $(SRC:sources/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS_DIR = objbonus
OBJ_BONUS = $(SRCBONUS:sources_bonus/%.c=$(OBJ_BONUS_DIR)/%.o)

INCLS = -I ./includes/
INCLS_BONUS = -I ./includes_bonus/

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBINCL = -L libft/ -lft

MLX_PATH = ./mlx
MLX = $(MLX_PATH)/libmlx_Linux.a
MLXFLAGS = -L mlx/ -lmlx -lXext -lX11 -lm

DEPS = $(OBJ:%.o=%.d)

# --- Compilation des fichiers sources ---
$(OBJ_DIR)/%.o: sources/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLS) -I libft/sources -I mlx -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: sources_bonus/%.c | $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) $(INCLS_BONUS) -I libft/sources -I mlx -c $< -o $@

# --- Règles principales ---
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBINCL) $(MLXFLAGS)
	@echo "✅ so_long created"

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(LIBINCL) $(MLXFLAGS)
	@echo "✅ so_long_bonus created"

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) all -s
	@echo "📦 Libft ready"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	mkdir -p $(OBJ_BONUS_DIR)

bonus: $(NAME_BONUS)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@echo "🧹 Cleaned up"

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "🔥 Fully cleaned up"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re bonus libft

