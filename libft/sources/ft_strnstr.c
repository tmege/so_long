/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:36:19 by acloos            #+#    #+#             */
/*   Updated: 2022/05/13 15:57:23 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	str[] = "lorem ipsum dolor sit amet";
	const char	to_find[] = "dolor";

	printf("%s", ft_strnstr(str, to_find, 15));
	return (0);
}
*/
