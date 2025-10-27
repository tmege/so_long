/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:55:44 by acloos            #+#    #+#             */
/*   Updated: 2022/06/07 11:58:24 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;

	elem = *lst;
	if (*lst == NULL)
		return ;
	while (*lst != NULL)
	{
		elem = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = elem;
	}
	(*lst) = NULL;
}
