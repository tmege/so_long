/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:36:46 by acloos            #+#    #+#             */
/*   Updated: 2022/06/03 12:08:46 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}

/*
int	main(void)
{
	char	string[10] = "bonjour";

	ft_putendl_fd(string, 1);
	return (0);
}
*/