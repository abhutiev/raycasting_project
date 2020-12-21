/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 16:55:39 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/19 17:34:38 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	delta_step_calculating(t_all *all)
{
	all->ray.x_direction = all->player.x_direction +
			all->ray.abscissa * all->ray.camera_plane;
	all->ray.y_direction = all->player.y_direction +
			all->ray.ordinate * all->ray.camera_plane;
	if (all->ray.y_direction)
	{
		all->ray.x_delta_step = (all->ray.x_direction ?
				fabs(1 / all->ray.x_direction) : 1);
	}
	else
	{
		all->ray.x_delta_step = 0;
	}
	if (all->ray.x_direction)
	{
		all->ray.y_delta_step = (all->ray.y_direction ?
				fabs(1 / all->ray.y_direction) : 1);
	}
	else
	{
		all->ray.y_delta_step = 0;
	}
}

void	camera_plane_shift(t_all *all)
{
	if (all->ray.x_direction >= 0)
	{
		all->ray.x_step = 1;
		all->ray.x_shift = (1.0 + all->ray.x_coord - all->player.x_coord)
				* all->ray.x_delta_step;
	}
	else
	{
		all->ray.x_step = -1;
		all->ray.x_shift = (all->player.x_coord - all->ray.x_coord) *
				all->ray.x_delta_step;
	}
	if (all->ray.y_direction >= 0)
	{
		all->ray.y_step = 1;
		all->ray.y_shift = (1.0 + all->ray.y_coord - all->player.y_coord) *
				all->ray.y_delta_step;
	}
	else
	{
		all->ray.y_step = -1;
		all->ray.y_shift = (all->player.y_coord - all->ray.y_coord) *
				all->ray.y_delta_step;
	}
}

void	calculate_ray_length(t_all *all)
{
	if (all->ray.sector == 3 || all->ray.sector == 4)
	{
		all->ray.length = (all->ray.x_coord - all->player.x_coord
				+ (1 - all->ray.x_step) / 2) / all->ray.x_direction;
	}
	else if (all->ray.sector == 1 || all->ray.sector == 2)
	{
		all->ray.length = (all->ray.y_coord - all->player.y_coord
				+ (1 - all->ray.y_step) / 2) / all->ray.y_direction;
	}
}

void	calculate_wall_parameters(t_all *all)
{
	all->wall.height = (int)(all->config.y_resolution / all->ray.length);
	all->wall.moulding = (all->config.y_resolution - all->wall.height) / 2;
	all->wall.plinth = (all->config.y_resolution + all->wall.height) / 2;
	if (all->wall.plinth > all->config.y_resolution)
	{
		all->wall.moulding = 0;
		all->wall.plinth = all->config.y_resolution;
	}
	if (all->ray.sector == FIRST_SECTOR || all->ray.sector == SECOND_SECTOR)
		all->wall.coordinate = (all->player.x_coord + all->ray.length * all->ray.x_direction);
	else if (all->ray.sector == THIRD_SECTOR || all->ray.sector == FOURTH_SECTOR)
		all->wall.coordinate = (all->player.y_coord + all->ray.length * all->ray.y_direction);
	all->wall.coordinate -= floor(all->wall.coordinate);
	all->texture.x_coord = (int)(all->wall.coordinate *
			(double)all->texture.width);
	if (all->ray.sector == SECOND_SECTOR || all->ray.sector == THIRD_SECTOR)
		all->texture.x_coord = -all->texture.x_coord + all->texture.width - 1;
	all->texture.offset = (double)all->texture.height / all->wall.height;
	all->texture.coordinate = (all->wall.moulding -
	(all->config.y_resolution + all->wall.height) / 2) * all->texture.offset;
}

void 	get_width(t_all *all)
{
	if (all->ray.sector == FIRST_SECTOR)
	{
		all->texture.width = all->textures.north_wall.width;
	}
	if (all->ray.sector == SECOND_SECTOR)
	{
		all->texture.width = all->textures.south_wall.width;
	}
	if (all->ray.sector == THIRD_SECTOR)
	{
		all->texture.width = all->textures.west_wall.width;
	}
	if (all->ray.sector == FOURTH_SECTOR)
	{
		all->texture.width = all->textures.east_wall.width;
	}
}