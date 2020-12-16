/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:08:09 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/16 22:08:34 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rays_to_start(t_all *all)
{
	all->ray.x_coord = all->player.x_coord;
	all->ray.y_coord = all->player.y_coord;
}