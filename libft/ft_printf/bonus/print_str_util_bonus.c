/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_util_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:02:20 by acloos            #+#    #+#             */
/*   Updated: 2022/10/25 22:18:18 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	str_no_dash(t_printf *printed, int len)
{
	while (printed->width > len)
	{
		printed->width--;
		printed->len += write(1, " ", 1);
	}
}

void	str_dash(t_printf *printed, int len)
{
	printed->width -= len;
	while (printed->width > 0)
	{
		printed->len += write (1, " ", 1);
		printed->width--;
	}
}
