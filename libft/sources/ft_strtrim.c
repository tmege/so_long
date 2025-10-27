/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:37:03 by acloos            #+#    #+#             */
/*   Updated: 2022/06/03 09:51:47 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*neat;

	i = 0;
	j = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	if (*s1 && *set)
	{
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strrchr(set, s1[j - 1]) && j > i)
			j--;
	}
	neat = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!neat)
		return (NULL);
	ft_strlcpy(neat, &s1[i], (j - i + 1));
	return (neat);
}

/*
int	main(void)
{
	char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	char	set [] = "\t \n";
	char const *subbb;

	printf("%s\n", s1);
	subbb = ft_strtrim(s1, set);
	printf("et donc=%s", subbb);
}

*/