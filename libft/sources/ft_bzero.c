/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:35:22 by acloos            #+#    #+#             */
/*   Updated: 2022/06/01 15:58:51 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/*
int	main()
{
	char	welp[] = "hello world";

	printf("%s\n", welp);
	bzero(welp, 3);
//	ft_bzero(welp, 3);
	printf("%s", welp);
	return (0);
}
*/
