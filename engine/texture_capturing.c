/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_capturing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 05:50:23 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/16 05:55:44 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_textures_address(t_all *all)
{
	all->textures.north_wall.address =
	mlx_get_data_addr(all->textures.north_wall.instance,
	&(all->textures.north_wall.bits_per_pixel),
	&(all->textures.north_wall.size_line), &(all->textures.north_wall.endian));
	all->textures.south_wall.address =
	mlx_get_data_addr(all->textures.south_wall.instance,
	&(all->textures.south_wall.bits_per_pixel),
	&(all->textures.south_wall.size_line), &(all->textures.south_wall.endian));
	all->textures.east_wall.address =
	mlx_get_data_addr(all->textures.east_wall.instance,
	&(all->textures.east_wall.bits_per_pixel),
	&(all->textures.east_wall.size_line), &(all->textures.east_wall.endian));
	all->textures.west_wall.address =
	mlx_get_data_addr(all->textures.west_wall.instance,
	&(all->textures.west_wall.bits_per_pixel),
	&(all->textures.west_wall.size_line), &(all->textures.west_wall.endian));
	all->textures.sprite.address =
	mlx_get_data_addr(all->textures.sprite.instance,
	&(all->textures.sprite.bits_per_pixel),
	&(all->textures.sprite.size_line), &(all->textures.sprite.endian));
}

void	textures_capturing(t_all *all)
{
	all->textures.north_wall.instance = mlx_xpm_file_to_image(all->mlx,
			all->config.path_north, &(all->textures.north_wall.width),
								&(all->textures.north_wall.height));
	all->textures.south_wall.instance = mlx_xpm_file_to_image(all->mlx,
			all->config.path_south, &(all->textures.south_wall.width),
								&(all->textures.south_wall.height));
	all->textures.west_wall.instance = mlx_xpm_file_to_image(all->mlx,
		all->config.path_west, &(all->textures.west_wall.width),
							&(all->textures.west_wall.height));
	all->textures.east_wall.instance = mlx_xpm_file_to_image(all->mlx,
			all->config.path_east, &(all->textures.east_wall.width),
								&(all->textures.east_wall.height));
	all->textures.sprite.instance = mlx_xpm_file_to_image(all->mlx,
			all->config.path_sprite, &(all->textures.sprite.width),
								&(all->textures.sprite.height));
	get_textures_address(all);
	free_way_to_textures(all);
}
