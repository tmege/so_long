#include "so_long.h"

/*checking .ber extension */
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

/*checking that
- the file provided as a map is .ber
- the file exists
- the maps is valid
- the map is flood filled
*/
t_game	*valid_map(char *mappy, t_game *game)
{
	if (!check_xt(mappy))
	{
		ft_nomap(game, "Please provide a .ber map.\n");
		return (0);
	}
	if (!map_init(mappy, game))
	{
		ft_nomap(game, "Please provide a map.\n");
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
