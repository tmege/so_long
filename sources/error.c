#include "so_long.h"

int	ft_nomap(t_game *game, char *err_msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", err_msg);
	ft_printf("Can't play.\n");
	free(game);
	return (0);
}

int	ft_error(t_game *game, char *err_msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", err_msg);
	ft_printf("Can't play.\n");
	map_destroyer(game);
	free(game);
	return (0);
}
