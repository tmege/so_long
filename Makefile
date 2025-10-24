NAME 	= so_long

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

MLX_DIR = ./minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

SRCS 	=	./utils/ft_join_strings.c				\
			./utils/ft_itoa.c						\
            ./utils/ft_strdup.c                    \
			./utils/ft_get_map.c					\
			./utils/ft_moves.c 					\
			./utils/ft_split.c						\
			./utils/ft_put_image.c					\
			./utils/ft_put_text.c					\
			./get_next_line/get_next_line_utils.c	\
			./get_next_line/get_next_line.c			\
			./utils/ft_check_file_is_valid.c		\
			./utils/ft_check_map_utils.c			\
			./utils/ft_check_map.c					\
			./utils/ft_animation.c					\
			./utils/ft_animation_utils.c			\
			./utils/ft_exit_door.c					\
			so_long.c

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLX_FLAGS)
	@echo "\033[4;35m"
	@echo "  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      "
	@echo " ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     "
	@echo " ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      "
	@echo " ███        ███    ███        ███         ███    ███ ███   ███  ▄███            "
	@echo "███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      "
	@echo "         ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     "
	@echo "   ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     "
	@echo "▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀     "
	@echo "\033[0m"
	@echo "\033[44mBy: tmege\033[0m"

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
