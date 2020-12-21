/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 21:21:34 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/19 12:14:38 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_some_stuff(t_all *all)
{
	all->ray.abscissa = 0;
	all->ray.ordinate = 0;
	all->texture.width = 0;
	all->texture.height = 0;
	all->ray.length = 0;
}
