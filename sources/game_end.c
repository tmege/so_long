/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:52:09 by acloos            #+#    #+#             */
/*   Updated: 2023/03/11 11:20:27 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over_banner(void)
{
	ft_printf("\n\n%s", SLOW_BLINK);
	ft_printf("%s╔═╗╔═╗╔╦╗╔═╗  ╔═╗╦  ╦╔═╗╦═╗\n", F_L_YELLOW);
	ft_printf("%s║ ╦╠═╣║║║║╣   ║ ║╚╗╔╝║╣ ╠╦╝\n", F_L_GREY);
	ft_printf("%s╚═╝╩ ╩╩ ╩╚═╝  ╚═╝ ╚╝ ╚═╝╩╚═%s\n", F_L_MAGENTA, RST);
	ft_printf("%s\n", RST);
}

void	game_under(void)
{
	game_over_banner();
	ft_printf("\n...\n\n\t\tbefore it even began   ¯\\_(ツ)_/¯ \n\n\n");
}

void	game_over_victory(void)
{
	ft_printf("\n\n%s%sVICTORY ACHIEVED%s\n", F_D_YELLOW, BOLD, RST);
	game_over_banner();
}
