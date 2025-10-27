/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:36:22 by acloos            #+#    #+#             */
/*   Updated: 2022/06/01 16:00:40 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slen;

	slen = ft_strlen(s);
	while (slen >= 0)
	{
		if (s[slen] == (unsigned char)c)
			return ((char *)s + slen);
		slen--;
	}
	return (NULL);
}

/*
int	main()
{
   char a[50] = "Hello world";

   printf("Search H result is %s\n", ft_strrchr(a, 'H'));
   printf("Search z result is %s\n", ft_strrchr(a, 'z'));

   printf("Search H result is %s\n", strrchr(a, 'H'));
   printf("Search z result is %s\n", strrchr(a, 'z'));

   return 0;
}
*/
