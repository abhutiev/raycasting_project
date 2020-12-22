/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:08:09 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/19 17:35:45 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_casting(t_all *all)
{
	all->screen.x = 0;
	while (all->screen.x < all->config.x_resolution)
	{
		all->ray.camera_plane = 2 * all->screen.x /
				(double)all->config.x_resolution - 1;
		ray_to_start(all);
		delta_step_calculating(all);
		camera_plane_shift(all);
		wall_collide(all);
		calculate_ray_length(all);
		get_width(all);
		calculate_wall_parameters(all);
		rendering(all);
		all->screen.x += 1;
	}
	sprite_calculations_and_rendering(all);
}

void	ray_to_start(t_all *all)
{
	all->ray.x_coord = (int)all->player.x_coord;
	all->ray.y_coord = (int)all->player.y_coord;
}

void	wall_collide(t_all *all)
{
	while (RAY_NOT_CRASHED_INTO_WALL)
	{
		if (all->ray.x_shift < all->ray.y_shift)
		{
			all->ray.x_shift += all->ray.x_delta_step;
			all->ray.x_coord += all->ray.x_step;
			all->ray.sector = (all->ray.x_direction >= 0 ? 4 : 3);
		}
		else
		{
			all->ray.y_shift += all->ray.y_delta_step;
			all->ray.y_coord += all->ray.y_step;
			all->ray.sector = (all->ray.y_direction >= 0 ? 2 : 1);
		}
		if (all->map.map[all->ray.y_coord][all->ray.x_coord] == '1')
			return ;
	}
}
