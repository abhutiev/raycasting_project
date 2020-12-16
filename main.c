/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:52:13 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/16 22:08:29 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_ray_step(t_all *all)
{
	all->ray.x_direction = 
}

void	raycasting(t_all *all)
{
	size_t	i;

	i = 0;
	while (i < all->config.x_resolution)
	{
		all->ray.camera_plane = 2 * i / all->config.x_resolution - 1;
		rays_to_start(all);
		calculate_ray_step(all);
		
		i++;
	}
}

void	calculating(t_all *all)
{

}

void	rendering(t_all *all)
{

}

void	engine(t_all *all)
{
	create_image(all);
	textures_capturing(all);
	raycasting(all);
	calculating(all);
	rendering(all);
	combined_loop(all);
}


int		main(int argc, char **argv)
{
	t_all		all;

	program_arguments_checking(argc, argv);
	all = get_all_information_from_config(argv[1]);
	engine(&all);
	return (0);

}
