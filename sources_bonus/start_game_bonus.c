/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:19:16 by tmege             #+#    #+#             */
/*   Updated: 2025/11/06 17:19:18 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.line_size)
	{
		y = 0;
		while (y < game->map.col_size)
		{
			load_tiles(game, x, y);
			y++;
		}
		x++;
	}
}

void	display_game(t_game *game)
{
	display_map(game);
	mlx_key_hook(game->show.win_ptr, kb_input, game);
	mlx_hook(game->show.win_ptr, ClientMessage, LeaveWindowMask, \
		mlx_map_destroyer, game);
	mlx_loop(game->show.mlx_ptr);
}

int	start_game(t_game *game)
{
	game->show.mlx_ptr = mlx_init();
	if (!game->show.mlx_ptr)
	{
		ft_error(game, "Can't start mlx.\n");
		return (0);
	}
	game->show.x_win = game->map.line_size * TILE_SIZE;
	game->show.y_win = game->map.col_size * TILE_SIZE;
	game->show.win_ptr = mlx_new_window(game->show.mlx_ptr, game->show.x_win, \
		game->show.y_win, "So_long\n");
	if (!game->show.win_ptr)
	{
		mlx_destroy_display(game->show.mlx_ptr);
		free(game->show.mlx_ptr);
		ft_error(game, "Can't open window.\n");
		return (0);
	}
	if (xpm_load(game))
		display_game(game);
	return (1);
}
