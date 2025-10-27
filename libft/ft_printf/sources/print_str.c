/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:40:54 by acloos            #+#    #+#             */
/*   Updated: 2022/09/29 17:30:58 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(t_printf *printed)
{
	char	*print;

	print = va_arg(printed->ap, char *);
	if (!printed || printed == NULL || print == NULL)
	{
		printed->len += write(1, "(null)", 6);
		return (printed->len);
	}
	printed->len += (int)ft_strlen(print);
	ft_putstr_fd(print, 1);
	return (printed->len);
}
