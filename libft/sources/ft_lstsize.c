/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acloos <acloos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:56:05 by acloos            #+#    #+#             */
/*   Updated: 2022/06/07 11:58:00 by acloos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*elem;
	int		i;

	i = 0;
	elem = lst;
	while (elem != NULL)
	{
		elem = elem -> next;
		i++;
	}
	return (i);
}
