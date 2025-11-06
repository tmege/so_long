/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:18:02 by tmege             #+#    #+#             */
/*   Updated: 2025/11/06 17:18:04 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
