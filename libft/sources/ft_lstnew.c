/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:56:02 by acloos            #+#    #+#             */
/*   Updated: 2023/01/26 12:10:39 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (newlist == NULL)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
