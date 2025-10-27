/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:51:31 by acloos            #+#    #+#             */
/*   Updated: 2023/03/11 11:21:14 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_nomap(game, "Malloc error.");
		game_under();
	}
	if (argc != 2)
	{
		ft_nomap(game, "Syntax error detected !\n\
		Please use as :\n\t\t\t./so_long <map.ber>\n");
		game_under();
		return (2);
	}
	if (init_game_structs(game) && valid_map(argv[1], game))
		start_game(game);
	return (0);
}
