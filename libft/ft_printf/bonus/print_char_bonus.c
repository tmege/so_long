/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:39:22 by acloos            #+#    #+#             */
/*   Updated: 2022/10/25 19:38:47 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_char(t_printf *printed)
{
	char	a;

	a = va_arg(printed->ap, int);
	if (printed->dash == 0)
	{
		while (printed->width > 1)
		{
			printed->width--;
			printed->len += write(1, " ", 1);
		}
	}
	printed->len += write(1, &a, 1);
	if (printed->dash == 1)
	{
		while (printed->width > 1)
		{
			printed->len += write (1, " ", 1);
			printed->width--;
		}
	}
}
