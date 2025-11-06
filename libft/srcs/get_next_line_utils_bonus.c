/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmege <tmege@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:31:08 by tmege             #+#    #+#             */
/*   Updated: 2025/06/11 14:02:52 by tmege            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* calculate len */
size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/* search c in str */
char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

/* join str1 & str2 */
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	len = (ft_strlen_gnl(s1) + ft_strlen_gnl(s2));
	i = 0;
	str = malloc(len + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

t_fdnode	*get_fdnode(t_fdnode **head, int fd)
{
	t_fdnode	*current;
	t_fdnode	*new;

	current = *head;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	new = malloc(sizeof(t_fdnode));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->stash = NULL;
	new->next = *head;
	*head = new;
	return (new);
}

void	free_fdnode(t_fdnode **head, int fd)
{
	t_fdnode	*curr;
	t_fdnode	*prev;

	curr = *head;
	prev = NULL;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if (prev)
				prev->next = curr->next;
			else
				*head = curr->next;
			free(curr->stash);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
