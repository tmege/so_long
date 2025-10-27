/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:35:40 by acloos            #+#    #+#             */
/*   Updated: 2022/06/03 13:50:18 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/*int	main()
{

	int	test = 'a';
	printf("%d\n", ft_isprint(test));
	printf("%i", isprint(test));
	return (0);
}
 */
