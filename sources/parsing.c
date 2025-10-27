/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:51:48 by acloos            #+#    #+#             */
/*   Updated: 2023/03/15 12:23:43 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This function checks whether the file ends with the correct extension
It's fine if the name contains ALSO the extension within its name
But it HAS TO end with the correct extension

*/

int	check_xt(char *map)
{
	char	*name_end;
	char	*ext;

	ext = ".ber";
	name_end = ft_substr(map, (ft_strlen(map) - 4), 4);
	if (ft_strncmp(name_end, ext, ft_strlen(name_end)) != 0)
	{
		free(name_end);
		return (0);
	}
	free(name_end);
	return (1);
}

/*
This hub function checks that
	- the file provided as a map has the corect extension
	- the file exists
	- the maps is valid according to the project rules
		-> which means the characters used and pathfinding
As the pahfinding is done witha floodfill algo,
	the map stored in the program is altered
	that's why it is destroyed and re-initialized
(would like to check how to work on a deep copy, though)
Oh and no, an empty argument such as: ./so_long ""
	is not checked as a wrong extension
		yes it could... 
		but I felt the 2nd error message was more fitting
*/

t_game	*valid_map(char *mappy, t_game *game)
{
	if (!check_xt(mappy))
	{
		ft_nomap(game, "Please provide a map with a valid extension");
		return (0);
	}
	if (!map_init(mappy, game))
	{
		ft_nomap(game, "The map is a lie !\nPlease provide a map.");
		return (0);
	}
	if (!check_map(game))
		return (0);
	if (!flood_it(game))
		return (0);
	if (game->map.map)
		map_destroyer(game);
	map_init(mappy, game);
	return (game);
}
