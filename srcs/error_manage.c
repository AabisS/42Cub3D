/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:17:04 by fmarckma          #+#    #+#             */
/*   Updated: 2021/02/17 14:35:36 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	error_manage(int i)
{
	ft_putstr_fd("Error\n", 1);
	if (i == 0)
		ft_putstr_fd("Probleme de Resolution\n", 1);
	else if (i == 1)
		ft_putstr_fd("Probleme de path des textures NO\n", 1);
	else if (i == 2)
		ft_putstr_fd("Probleme de path des textures SO\n", 1);
	else if (i == 3)
		ft_putstr_fd("Probleme de path des textures WE\n", 1);
	else if (i == 4)
		ft_putstr_fd("Probleme de path des textures EA\n", 1);
	else if (i == 5)
	{
		ft_putstr_fd("Probleme d'allocation de Memoire\n", 1);
		return (1);
	}
	else if (i == 6)
		ft_putstr_fd("Probleme de path des Sprites\n", 1);
	else if (i == 7)
		ft_putstr_fd("Probleme de couleur RGB\n", 1);
	else if (i == 8)
		ft_putstr_fd("Probleme de path de sprite\n", 1);
	return (0);
}

int	error_manage2(int i)
{
	ft_putstr_fd("Error\n", 1);
	if (i == 9)
	{
		ft_putstr_fd("Mauvaise extension de fichier\n", 1);
		return (1);
	}
	else if (i == 10)
		ft_putstr_fd("Probleme de la MiniLibX\n", 1);
	else if (i == 11)
	{
		ft_putstr_fd("La map est ouverte\n", 1);
		return (1);
	}
	else if (i == 12)
	{
		ft_putstr_fd("Plusieur depart de Position sur la Map\n", 1);
		return (1);
	}
	else if (i == 13)
	{
		ft_putstr_fd("Prefixe manquant sur les informations de la carte", 1);
		return (1);
	}
	return (0);
}

int	error_manage3(int i)
{
	ft_putstr_fd("Error\n", 1);
	if (i == 14)
	{
		ft_putstr_fd("Aucun point de Depart du personnage\n", 1);
		return (1);
	}
	else if (i == 15)
	{
		ft_putstr_fd("Couleur identitique ou invalide\n", 1);
		return (1);
	}
	else if (i == 16)
	{
		ft_putstr_fd("Premiere ou derniere ligne invalide\n", 1);
		return (1);
	}
	else if (i == 17)
	{
		ft_putstr_fd("Trop de sprite pour le bon fonctionnement du programme",
		1);
		return (1);
	}
	return (0);
}
