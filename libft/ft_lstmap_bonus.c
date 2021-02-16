/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:00:33 by fmarckma          #+#    #+#             */
/*   Updated: 2019/10/18 12:44:51 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;

	if (lst)
	{
		if (!(new = ft_lstnew(f(lst->content))))
			ft_lstdelone(lst, del);
		new->next = ft_lstmap(lst->next, f, del);
		return (new);
	}
	return (NULL);
}
