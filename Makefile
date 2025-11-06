NAME        = so_long
NAME_BONUS  = so_long_bonus
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -MMD
RM          = rm -rf

SRC_DIR     = sources
BONUS_DIR   = sources_bonus
OBJ_DIR     = obj
OBJ_BONUS_DIR = objbonus
INCL_DIR    = includes
INCL_BONUS_DIR = includes_bonus

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
LIBINCL     = -L $(LIBFT_DIR) -lft

MLX_DIR     = mlx
MLXFLAGS    = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_NAMES = main error struct_init struct_tiles_init \
	parsing map_init check_map flood_fill elem_pos \
	start_game ft_xpm events_hook tiles move mlx_closing game_end

SRC         = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_NAMES)))
SRC_BONUS   = $(addprefix $(BONUS_DIR)/, $(addsuffix _bonus.c, $(SRC_NAMES)))

OBJ         = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS   = $(SRC_BONUS:$(BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)
DEPS        = $(OBJ:.o=.d)

# ========================
#        RULES
# ========================

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBINCL) $(MLXFLAGS)
	@echo "✅ $@ ready"

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $@ $(LIBINCL) $(MLXFLAGS)
	@echo "✅ $@ ready"

# === Compilation ===
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCL_DIR) -I $(LIBFT_DIR)/sources -I $(MLX_DIR) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c | $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) -I $(INCL_BONUS_DIR) -I $(LIBFT_DIR)/sources -I $(MLX_DIR) -c $< -o $@

# === Dossiers objets ===
$(OBJ_DIR) $(OBJ_BONUS_DIR):
	mkdir -p $@

# === Libft ===
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all -s
	@echo "📦 Libft ready"

# === Nettoyage ===
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@echo "🧹 Cleaned"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "🔥 Fully cleaned"

re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re

