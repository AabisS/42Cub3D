/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:34:58 by fmarckma          #+#    #+#             */
/*   Updated: 2019/10/17 18:17:52 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *ptr;

	ptr = (*alst);
	if (!(*alst))
	{
		new->next = *alst;
		*alst = new;
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}
