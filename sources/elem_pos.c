/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:16:44 by tmege             #+#    #+#             */
/*   Updated: 2025/11/06 17:16:51 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*initialize values of struct:
- s_character : player
- s_tile : exit position
*/

void	player_pos(int i, int j, t_game *game)
{
	game->player.x_char = j;
	game->player.y_char = i;
}

void	exit_pos(int i, int j, t_game *game)
{
	game->exit.x_tile = j;
	game->exit.y_tile = i;
}

/*run through the map & identify the x/y position of character and exit
*/

t_game	*elem_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.col_size - 1)
	{
		j = 0;
		while (game->map.map[i][j] != '\n')
		{
			if (game->map.map[i][j] == 'P')
				player_pos(i, j, game);
			if (game->map.map[i][j] == 'E')
				exit_pos(i, j, game);
			j++;
		}
		i++;
	}
	return (game);
}

/*display a message if there is no P or E or C
if several are missing, the 1st message only is displayed
*/

int	mission_ready(t_game *game)
{
	if (game->map.hero_count == 0)
	{
		ft_error(game, "No hero :( ");
		return (0);
	}
	if (game->map.exit_count == 0)
	{
		ft_error(game, "No way out ;( ");
		return (0);
	}
	if (game->map.item_count == 0)
	{
		ft_error(game, "No items :( ");
		return (0);
	}
	game = elem_pos(game);
	return (1);
}
