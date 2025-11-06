#include "so_long.h"

void	game_over_banner(void)
{
	ft_printf("\nDone.\n");
}

void	game_under(void)
{
	game_over_banner();
	ft_printf("\n...\nDidn't even start.\n");
}

void	game_over_victory(void)
{
	ft_printf("\nVICTORY !!!\n");
	game_over_banner();
}
