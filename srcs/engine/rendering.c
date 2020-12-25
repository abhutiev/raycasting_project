/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 00:27:41 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/21 00:27:45 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ceiling_rendering(t_all *all)
{
	all->screen.y = 0;
	while (all->screen.y < all->wall.moulding)
	{
		put_to_image(all, all->config.rgb_ceiling);
		all->screen.y++;
	}
}

static void		floor_rendering(t_all *all)
{
	all->screen.y = all->wall.plinth;
	while (all->screen.y < all->config.y_resolution)
	{
		put_to_image(all, all->config.rgb_floor);
		all->screen.y++;
	}
}

static void		choose_texture(t_all *all)
{
	if (all->ray.sector == FIRST_SECTOR)
	{
		all->texture.height = all->textures.north_wall.height;
		all->texture.width = all->textures.north_wall.width;
		get_color_from_texture(all, all->textures.north_wall);
	}
	if (all->ray.sector == SECOND_SECTOR)
	{
		all->texture.height = all->textures.south_wall.height;
		all->texture.width = all->textures.south_wall.width;
		get_color_from_texture(all, all->textures.south_wall);
	}
	if (all->ray.sector == THIRD_SECTOR)
	{
		all->texture.height = all->textures.west_wall.height;
		all->texture.width = all->textures.west_wall.width;
		get_color_from_texture(all, all->textures.west_wall);
	}
	if (all->ray.sector == FOURTH_SECTOR)
	{
		all->texture.height = all->textures.east_wall.height;
		all->texture.width = all->textures.east_wall.width;
		get_color_from_texture(all, all->textures.east_wall);
	}
}

static void		wall_rendering(t_all *all)
{
	all->screen.y = all->wall.moulding;
	while (all->screen.y < all->wall.plinth)
	{
		choose_texture(all);
		all->texture.y_coord = (int)all->texture.coordinate
				& (all->texture.height - 1);
		all->texture.coordinate += all->texture.offset;
		put_to_image(all, all->texture.color);
		all->screen.y++;
	}
}

void			rendering(t_all *all)
{
	ceiling_rendering(all);
	floor_rendering(all);
	wall_rendering(all);
}
