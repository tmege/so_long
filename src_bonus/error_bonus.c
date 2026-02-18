/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:17:07 by tmege             #+#    #+#             */
/*   Updated: 2025/11/06 17:17:10 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
