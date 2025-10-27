/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:37:07 by acloos            #+#    #+#             */
/*   Updated: 2023/03/11 12:41:44 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	closing(t_game *game)
{
	mlx_map_destroyer(game);
	return (0);
}

void	motion(int keycode, t_game *game)
{
	if (keycode == K_W || keycode == K_Z || keycode == K_AR_U || keycode == K_K)
		move_up(game);
	else if (keycode == K_A || keycode == K_Q || keycode == K_AR_L || \
		keycode == K_H)
		move_left(game);
	else if (keycode == K_S || keycode == K_AR_D || keycode == K_J)
		move_down(game);
	else if (keycode == K_D || keycode == K_AR_R || keycode == K_L)
		move_right(game);
}

int	kb_input(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		mlx_map_destroyer(game);
	else
		motion(keycode, game);
	return (0);
}
