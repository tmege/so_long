#include "so_long.h"

/*record the numbers of special characters P, C, E
if the number is not valid, it displays an error msg accordingly
*/

int	check_char(char iji, t_game *game)
{
	char	*char_ok;

	char_ok = "01EPC";
	if (iji == 'P')
		game->map.hero_count++;
	if (iji == 'E')
		game->map.exit_count++;
	if (iji == 'C')
		game->map.item_count++;
	if (!ft_strchr(char_ok, iji))
	{
		ft_error(game, "This map contains invalid character(s)!\n\
		Valid characters are : 0 1 P E C\n\
		Please provide a valid map.\n");
		return (0);
	}
	if (game->map.hero_count > 1 || game->map.exit_count > 1)
	{
		if (game->map.hero_count > 1)
			ft_error(game, "Too many players on the map.");
		else if (game->map.exit_count > 1)
			ft_error(game, "Too many exits on the map.");
		return (0);
	}
	return (1);
}
/*
goes through the map and verifies every character with check_char()
*/

int	valid_char(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->map.col_size - 1)
	{
		j = 0;
		while (game->map.map[i][j] != '\n')
		{
			if (!check_char(game->map.map[i][j], game))
				return (0);
			j++;
		}
		i++;
	}
	if (!mission_ready(game))
		return (0);
	return (1);
}

/*
check if the map is fully enclosed with walls
- checks all of 1st and last line
- checks first and last character of all intermediate lines
*/

int	closed_up(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.col_size && j < game->map.line_size)
	{
		while (j < game->map.line_size)
		{
			if (game->map.map[i][0] != '1' ||
				game->map.map[i][game->map.line_size - 1] != '1' ||
				game->map.map[0][j] != '1' ||
				game->map.map[game->map.col_size - 1][j] != '1')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

/*
check that the shape of the map is rectangular
check that all lines have the same length as the first
*/

int	shape(t_game *game)
{
	int	i;
	int	check;

	i = 0;
	check = game->map.line_size;
	while (++i < game->map.col_size - 1)
	{
		if (game->map.map[i][0] == '\n')
			return (0);
		if (!(game->map.map[i][check - 1] && game->map.map[i][check] == '\n'))
			return (0);
	}
	if (game->map.map[i][check] != 0)
	{
		if (game->map.map[i][check] == 'n' && game->map.map[i][check + 1] != 0)
			return (0);
	}
	return (1);
}

/*
This function is a hub to check everything else
*/

int	check_map(t_game *game)
{
	if (!shape(game))
	{
		ft_error(game, "Please provide a rectangular map.");
		return (0);
	}
	if (!closed_up(game))
	{
		ft_error(game, "Please provide a closed map.");
		return (0);
	}
	if (!valid_char(game))
		return (0);
	return (1);
}
