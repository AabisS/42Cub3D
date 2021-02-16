/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:34:45 by fmarckma          #+#    #+#             */
/*   Updated: 2019/10/17 16:57:07 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	p_list(t_list *list)
{
	while (list)
	{
		ft_putstr_fd(list->content, 1);
		ft_putstr_fd("\n", 1);
		list = list->next;
	}
}
