/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:15:43 by user42            #+#    #+#             */
/*   Updated: 2021/02/10 15:22:56 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		fill_resolution(t_parse *info, char *str)
{
	int i;

	i = 1;
	i = down_space(str, i);
	info->width = ft_atoi(str + i);
	if (!info->width || info->width < 0)
		return (error_manage(0));
	while (ft_isdigit(str[i]))
		i++;
	while (!(ft_isdigit(str[i])))
		i++;
	info->height = ft_atoi(str + i);
	if (!info->height || info->height < 0)
		return (error_manage(0));
	if (info->width > 1920)
		info->width = 1920;
	if (info->height > 950)
		info->height = 950;
	return (1);
}

void	fill_path_no(t_parse *info, char *str)
{
	int i;
	int j;

	j = 0;
	i = 2;
	i = down_space(str, i);
	while (str[i])
		info->text_no[j++] = str[i++];
	info->text_no[j] = '\0';
}

void	fill_path_so(t_parse *info, char *str)
{
	int i;
	int j;

	j = 0;
	i = 2;
	i = down_space(str, i);
	while (str[i])
		info->text_so[j++] = str[i++];
	info->text_so[j] = '\0';
}

void	fill_path_we(t_parse *info, char *str)
{
	int i;
	int j;

	j = 0;
	i = 2;
	i = down_space(str, i);
	while (str[i])
		info->text_we[j++] = str[i++];
	info->text_we[j] = '\0';
}

void	fill_path_ea(t_parse *info, char *str)
{
	int i;
	int j;

	j = 0;
	i = 2;
	i = down_space(str, i);
	while (str[i])
		info->text_ea[j++] = str[i++];
	info->text_ea[j] = '\0';
}
