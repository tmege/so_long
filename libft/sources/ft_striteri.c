/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:36:55 by acloos            #+#    #+#             */
/*   Updated: 2022/06/03 13:44:36 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/* static void f(unsigned int i, char *c)
{
	*c = *c + i;
}

int main()
{
	char str1[] = "abc";
	size_t	len = ft_strlen(str1);
	printf("%s\n", str1);
	ft_striteri(str1, f);
	printf("%i", ft_strncmp("abc", str1, len));
} */
