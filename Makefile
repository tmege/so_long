NAME        = so_long
NAME_BONUS  = so_long_bonus
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -MMD
RM          = rm -rf

SRC_DIR     = src
BONUS_DIR   = src_bonus
OBJ_DIR     = obj
OBJ_BONUS_DIR = obj_bonus
INC_DIR     = inc
INC_BONUS_DIR = inc_bonus

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
LIBINCL     = -L $(LIBFT_DIR) -lft

MLX_DIR     = minilibx-linux
MLX         = $(MLX_DIR)/libmlx.a
MLXFLAGS    = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_NAMES = main error struct_init struct_tiles_init \
	parsing map_init check_map flood_fill elem_pos \
	start_game ft_xpm events_hook tiles move mlx_closing game_end

SRC         = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_NAMES)))
SRC_BONUS   = $(addprefix $(BONUS_DIR)/, $(addsuffix _bonus.c, $(SRC_NAMES)))

OBJ         = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS   = $(SRC_BONUS:$(BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)
DEPS        = $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

# ========================
#        RULES
# ========================

all: $(MLX) $(LIBFT) $(NAME)

bonus: $(MLX) $(LIBFT) $(NAME_BONUS)

# === Executables ===
$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBINCL) $(MLXFLAGS)
	@echo "✅ $@ ready"

$(NAME_BONUS): $(OBJ_BONUS) Makefile
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $@ $(LIBINCL) $(MLXFLAGS)
	@echo "✅ $@ ready"

# === Compilation ===
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR)/includes -I $(MLX_DIR) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c Makefile | $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) -I $(INC_BONUS_DIR) -I $(LIBFT_DIR)/includes -I $(MLX_DIR) -c $< -o $@

# === Object directories ===
$(OBJ_DIR) $(OBJ_BONUS_DIR):
	mkdir -p $@

# === External libraries ===
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all -s
	@echo "📦 Libft ready"

$(MLX):
	@$(MAKE) -C $(MLX_DIR) all > /dev/null 2>&1
	@echo "🪟 MinilibX ready"

# === Cleanup ===
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean -s
	@$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@echo "🧹 Cleaned"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean -s
	@$(MAKE) -C $(MLX_DIR) clean > /dev/null 2>&1
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "🔥 Fully cleaned"

re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re
