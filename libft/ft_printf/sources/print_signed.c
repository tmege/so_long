/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:40:02 by acloos            #+#    #+#             */
/*   Updated: 2022/09/29 17:31:02 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_signed(t_printf *printed)
{
	int		nbr;
	char	*nbstr;

	nbr = va_arg(printed->ap, int);
	ft_putnbr_fd(nbr, 1);
	nbstr = ft_itoa((int)nbr);
	printed->len += ft_strlen(nbstr);
	free (nbstr);
}
