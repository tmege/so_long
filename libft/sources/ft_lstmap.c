/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:55:59 by acloos            #+#    #+#             */
/*   Updated: 2022/06/07 11:58:03 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mappy;
	t_list	*mapped;

	mappy = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		mapped = ft_lstnew(f(lst->content));
		if (!(mapped))
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&mappy, mapped);
		lst = lst->next;
	}
	return (mappy);
}
