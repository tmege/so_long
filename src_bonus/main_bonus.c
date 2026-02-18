/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:18:10 by tmege             #+#    #+#             */
/*   Updated: 2025/11/06 17:18:11 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_nomap(game, "Malloc error.\n");
		game_under();
	}
	if (argc != 2)
	{
		ft_nomap(game, "Syntax error.\nHTU:\n./so_long <map.ber>\n");
		game_under();
		return (2);
	}
	if (init_game_structs(game) && valid_map(argv[1], game))
		start_game(game);
	return (0);
}
