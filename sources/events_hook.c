/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:17:36 by tmege             #+#    #+#             */
/*   Updated: 2025/11/06 17:17:38 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closing(t_game *game)
{
	mlx_map_destroyer(game);
	return (0);
}

void	motion(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 122 || keycode == 65362)
		move_up(game);
	else if (keycode == 97 || keycode == 113 || keycode == 65361)
		move_left(game);
	else if (keycode == 115 || keycode == 65364)
		move_down(game);
	else if (keycode == 100 || keycode == 65363)
		move_right(game);
}

int	kb_input(int keycode, t_game *game)
{
	if (keycode == 65307)
		mlx_map_destroyer(game);
	else
		motion(keycode, game);
	return (0);
}
