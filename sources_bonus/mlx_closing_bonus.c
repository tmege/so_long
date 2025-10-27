/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_closing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:51:08 by acloos            #+#    #+#             */
/*   Updated: 2023/03/10 22:20:57 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
This function frees the map, line by line
*/

void	map_destroyer(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.col_size)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}

void	mlx_img_destroyer(t_game *game)
{
	if (game->hero.img)
		mlx_destroy_image(game->show.mlx_ptr, game->hero.img);
	if (game->item.img)
		mlx_destroy_image(game->show.mlx_ptr, game->item.img);
	if (game->exit.img)
		mlx_destroy_image(game->show.mlx_ptr, game->exit.img);
	if (game->floor.img)
		mlx_destroy_image(game->show.mlx_ptr, game->floor.img);
	if (game->wall.img)
		mlx_destroy_image(game->show.mlx_ptr, game->wall.img);
}

void	mlx_destroyer(t_game *game)
{
	mlx_img_destroyer(game);
	mlx_destroy_window(game->show.mlx_ptr, game->show.win_ptr);
	mlx_destroy_display(game->show.mlx_ptr);
	free(game->show.mlx_ptr);
}

int	mlx_map_destroyer(t_game *game)
{
	mlx_img_destroyer(game);
	mlx_destroy_window(game->show.mlx_ptr, game->show.win_ptr);
	mlx_destroy_display(game->show.mlx_ptr);
	free(game->show.mlx_ptr);
	map_destroyer(game);
	free(game);
	exit(EXIT_SUCCESS);
}
