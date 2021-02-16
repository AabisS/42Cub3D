/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:46:40 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/10 15:17:39 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

int	down_space(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int	rgb_to_integer(int nb1, int nb2, int nb3)
{
	int nb_final;

	nb_final = (65536 * nb1) + (256 * nb2) + nb3;
	return (nb_final);
}

int	verif_info(t_parse *info)
{
	if (!info->height || !info->width || info->text_ea[0] == '\0' ||
	info->text_no[0] == '\0' || info->text_so[0] == '\0' ||
	info->text_we[0] == '\0' || info->text_s[0] == '\0')
		return (error_manage2(13));
	else if ((!info->fcolor && !info->ccolor) || (info->fcolor == info->ccolor)
	|| info->rgb_invalid)
		return (error_manage3(15));
	else if (!info->err)
		return (error_manage3(14));
	else
		return (0);
}

int	is_same(t_parse *str, char *av)
{
	int i;

	str->save = "--save";
	i = 0;
	while (av[i++])
		if (av[i] != str->save[i])
			return (0);
	return (1);
}

int	verif_rgb(t_parse *info, int nb1, int nb2, int nb3)
{
	if (nb1 < 0 || nb1 > 255)
	{
		info->rgb_invalid = 1;
		return (error_manage(7));
	}
	if (nb2 < 0 || nb2 > 255)
	{
		info->rgb_invalid = 1;
		return (error_manage(7));
	}
	if (nb3 < 0 || nb3 > 255)
	{
		info->rgb_invalid = 1;
		return (error_manage(7));
	}
	return (1);
}
