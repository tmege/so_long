/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:35:46 by acloos            #+#    #+#             */
/*   Updated: 2022/06/03 12:05:07 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*memarea;
	unsigned char		carac;

	memarea = (const unsigned char *) s;
	carac = (unsigned char)c;
	while (n > 0)
	{
		if (*memarea == carac)
			return ((void *)memarea);
		n--;
		memarea++;
	}
	return (NULL);
}
/*
int		main()
{
	void *s = "bonjour";
	size_t	i = 4;
	int	c = 98;
	
	ft_memchr(s, c, i);
	return (0);
}
*/
