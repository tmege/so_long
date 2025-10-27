# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acloos <acloos@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 08:09:05 by acloos            #+#    #+#              #
#    Updated: 2023/03/11 12:14:13 by acloos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	so_long
NAME_BONUS				=	so_long_bonus

CC					=	gcc
CFLAGS					=	-Wall -Wextra -Werror -g3 -MMD
RM						=	rm -rf

SRCBAZ					=	main error struct_init struct_tiles_init \
						parsing map_init check_map flood_fill elem_pos \
						start_game ft_xpm events_hook tiles move mlx_closing game_end \
               
SRC					=	$(addsuffix .c, $(addprefix sources/, $(SRCBAZ)))

SRCADD					=	$(SRCBAZ) # add extra files
SRCBONUS				=	$(addsuffix _bonus.c, $(addprefix sources_bonus/, $(SRCADD)))

OBJ_DIR					=	obj
OBJ						=	$(SRC:sources/%.c=$(OBJ_DIR)/%.o)

INCLS					=	-I ./includes/
INCLS_BONUS				=	-I ./includes_bonus/

OBJ_BONUS_DIR				=	objbonus
OBJ_BONUS				=	$(SRCBONUS:sources_bonus/%.c=$(OBJ_BONUS_DIR)/%.o)

LIBFT_PATH				=	./libft
LIBFT					=	$(LIBFT_PATH)/libft.a
LIBINCL					=	-L libft/ -lft

MLX_PATH				=	./mlx
MLX						=	$(MLX_PATH)/libmlx_Linux.a
MLXFLAGS					=	-L mlx/ -lmlx -lXext -lX11

DEPS					=	$(OBJ:%.o=%.d)

$(OBJ_DIR)/%.o:			sources/%.c
						$(CC) $(CFLAGS) -I libft/sources -I mlx -I sources  -c $< -o $@ $(INCLS)

$(OBJ_BONUS_DIR)/%.o:	sources_bonus/%.c
						$(CC) $(CFLAGS) -I libft/sources -I mlx -I sources -c $< -o $@ $(INCLS_BONUS) $(LIBINCL) $(MLXFLAGS)

all:					$(NAME) 
						@echo "\033[32m[Program is ready for use]\033[0m"


$(NAME):				$(LIBFT) $(OBJ_DIR) $(OBJ)
						$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBINCL) $(MLXFLAGS)
						@echo "\033[32m[so_long created]\033[0m"
						
$(NAME_BONUS):				$(LIBFT) $(OBJ_BONUS_DIR) $(OBJ_BONUS)
						$(CC) $(CFLAGS)  $(OBJ_BONUS) -o $(NAME_BONUS) $(LIBINCL) $(MLXFLAGS)
						@echo "\033[32m[so_long_bonus created]\033[0m"						
						

$(LIBFT):
						$(MAKE) -C $(LIBFT_PATH) all -s
						@echo "\033[32m[Libft created]\033[0m"

$(OBJ_DIR):
						mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
						mkdir -p $(OBJ_BONUS_DIR)

-include $(DEPS)

bonus:					$(NAME_BONUS)

clean:
						$(MAKE) -C $(LIBFT_PATH) clean
						$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)
						@echo "\033[33m[Cleaned up]\033[0m"

fclean:					clean
						$(MAKE) -C $(LIBFT_PATH) fclean
						$(RM) $(NAME) $(NAME_BONUS)
						@echo "\033[33m[Fully cleaned up]\033[0m"

re:						fclean 
						make all
# pour compiler plus vite => ecrire: make -j re

.PHONY:	all clean fclean re bonus libft
